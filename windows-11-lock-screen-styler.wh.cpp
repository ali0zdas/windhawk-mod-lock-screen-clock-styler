// ==WindhawkMod==
// @id              windows-11-lock-screen-styler
// @name            Windows 11 Lock Screen Styler
// @description     Customize the Windows 11 lock screen with modern clock styles, date display, and widget controls.
// @version         0.1.0
// @author          ali0zdas
// @github          https://github.com/ali0zdas
// @include         LockApp.exe
// @architecture    x86-64
// @compilerOptions -lole32 -loleaut32 -lruntimeobject -lshlwapi
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Windows 11 Lock Screen Styler

Customize and enhance the Windows 11 lock screen with modern clock designs, frosted glass panels, dynamic date capsules, and clean layout controls.

## Features:
- **Modern Flip Clock:** Split glass cards for hour and minute with an elegant horizontal flip seam.
- **Frosted Glass / Acrylic Styling:** Translucent glass panels with subtle border highlights and rounded corners.
- **Dynamic Date Display:** Elegant date and day capsule positioned beneath the clock, adapting to the user's system locale.
- **Hide Default Widgets:** Clean up the lock screen by hiding MSN weather, sports, and news widgets.
- **Hide / Replace Default Clock:** Seamlessly replace the stock Windows 11 clock with custom styles or adjust vertical offsets.
- **Extensive Customization:** Card opacity, corner radius, font size, vertical offsets, and alignments are fully customizable via settings.

## Security Note:
This mod exclusively targets `LockApp.exe`. It does not inject into or interfere with `LogonUI.exe` or `winlogon.exe` in the Secure Desktop, preventing any system lockup or logon security risks.
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
- clockStyle: flip
  $name: "Clock Style"
  $description: "The clock style to display on the lock screen."
  $options:
    - flip: "Frosted Glass Flip Clock"
    - minimal: "Minimalist Digital Clock"
    - defaultOnly: "Default Clock Only (Widgets Hidden)"
- glassOpacity: 45
  $name: "Glass Opacity (Liquid Glass Alpha)"
  $description: "Translucency level of the flip cards (0 to 255; 0 is completely transparent, 255 is fully opaque)."
- cardCornerRadius: 22
  $name: "Card Corner Radius (px)"
  $description: "Corner curvature radius of the flip clock cards."
- clockFontSize: 92
  $name: "Digit Font Size"
  $description: "Font size for hour and minute digits."
- verticalOffset: 0
  $name: "Vertical Offset (px)"
  $description: "Offset to shift the clock vertically up or down (-200 to +400)."
- clockAlignment: center
  $name: "Clock Horizontal Alignment"
  $description: "Horizontal alignment of the clock on screen."
  $options:
    - center: "Center of Screen"
    - left: "Left Side"
    - right: "Right Side"
- hideDefaultWidgets: true
  $name: "Hide Default Widgets"
  $description: "Hides MSN weather, sports, and news widget areas on the lock screen."
- hideDefaultClock: true
  $name: "Hide Default Lock Screen Clock"
  $description: "Hides the default Windows 11 clock and date text to make way for the new clock."
- showDateCapsule: true
  $name: "Show Date Capsule"
  $description: "Displays a date and weekday capsule below the flip clock cards."
*/
// ==/WindhawkModSettings==

#include <windows.h>
#undef GetCurrentTime
#include <windhawk_api.h>
#include <xamlom.h>
#include <ocidl.h>
#include <Unknwn.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.UI.h>
#include <winrt/Windows.UI.Text.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.Media.h>
#include <winrt/Windows.UI.Xaml.Shapes.h>
#include <string>
#include <chrono>

namespace wux = winrt::Windows::UI::Xaml;
namespace wuxc = winrt::Windows::UI::Xaml::Controls;
namespace wuxm = winrt::Windows::UI::Xaml::Media;
namespace wuxs = winrt::Windows::UI::Xaml::Shapes;
namespace wu = winrt::Windows::UI;

// Mod Configuration Settings
struct ModSettings {
    std::wstring clockStyle;
    int glassOpacity;
    int cardCornerRadius;
    int clockFontSize;
    int verticalOffset;
    std::wstring clockAlignment;
    bool hideDefaultWidgets;
    bool hideDefaultClock;
    bool showDateCapsule;
} g_settings;

// Settings Loader
void LoadSettings() {
    PCWSTR styleStr = Wh_GetStringSetting(L"clockStyle");
    g_settings.clockStyle = (styleStr && *styleStr) ? styleStr : L"flip";
    Wh_FreeStringSetting(styleStr);

    g_settings.glassOpacity = Wh_GetIntSetting(L"glassOpacity");
    if (g_settings.glassOpacity <= 0 || g_settings.glassOpacity > 255) {
        g_settings.glassOpacity = 45;
    }

    g_settings.cardCornerRadius = Wh_GetIntSetting(L"cardCornerRadius");
    if (g_settings.cardCornerRadius < 0) {
        g_settings.cardCornerRadius = 22;
    }

    g_settings.clockFontSize = Wh_GetIntSetting(L"clockFontSize");
    if (g_settings.clockFontSize <= 0) {
        g_settings.clockFontSize = 92;
    }

    g_settings.verticalOffset = Wh_GetIntSetting(L"verticalOffset");

    PCWSTR alignStr = Wh_GetStringSetting(L"clockAlignment");
    g_settings.clockAlignment = (alignStr && *alignStr) ? alignStr : L"center";
    Wh_FreeStringSetting(alignStr);

    g_settings.hideDefaultWidgets = Wh_GetIntSetting(L"hideDefaultWidgets") != 0;
    g_settings.hideDefaultClock = Wh_GetIntSetting(L"hideDefaultClock") != 0;
    g_settings.showDateCapsule = Wh_GetIntSetting(L"showDateCapsule") != 0;

    Wh_Log(L"Settings loaded: style=%s, opacity=%d, font=%d, hideWidgets=%d, hideClock=%d",
           g_settings.clockStyle.c_str(), g_settings.glassOpacity,
           g_settings.clockFontSize, g_settings.hideDefaultWidgets, g_settings.hideDefaultClock);
}

// Flip Clock UI References
wuxc::TextBlock g_hourTextBlock{ nullptr };
wuxc::TextBlock g_minTextBlock{ nullptr };
wuxc::TextBlock g_dateTextBlock{ nullptr };
wux::DispatcherTimer g_clockTimer{ nullptr };
bool g_flipClockInjected = false;

// Update Time and Date
void UpdateTimeAndDate() {
    if (!g_hourTextBlock || !g_minTextBlock) {
        return;
    }

    SYSTEMTIME st;
    GetLocalTime(&st);

    WCHAR hourBuf[8];
    swprintf_s(hourBuf, L"%02d", st.wHour);

    WCHAR minBuf[8];
    swprintf_s(minBuf, L"%02d", st.wMinute);

    g_hourTextBlock.Text(hourBuf);
    g_minTextBlock.Text(minBuf);

    if (g_dateTextBlock && g_settings.showDateCapsule) {
        WCHAR dateBuf[128];
        if (GetDateFormatW(LOCALE_USER_DEFAULT, DATE_LONGDATE, &st, nullptr, dateBuf, ARRAYSIZE(dateBuf)) > 0) {
            g_dateTextBlock.Text(dateBuf);
        }
    }
}

// Build Flip Clock UI Element
wux::UIElement BuildFlipClockElement() {
    wuxc::Grid rootContainer;
    rootContainer.Name(L"WindhawkFlipClockContainer");

    // Horizontal Alignment
    if (g_settings.clockAlignment == L"left") {
        rootContainer.HorizontalAlignment(wux::HorizontalAlignment::Left);
        rootContainer.Margin(wux::Thickness{ 80.0, (double)g_settings.verticalOffset, 0.0, 0.0 });
    } else if (g_settings.clockAlignment == L"right") {
        rootContainer.HorizontalAlignment(wux::HorizontalAlignment::Right);
        rootContainer.Margin(wux::Thickness{ 0.0, (double)g_settings.verticalOffset, 80.0, 0.0 });
    } else {
        rootContainer.HorizontalAlignment(wux::HorizontalAlignment::Center);
        rootContainer.Margin(wux::Thickness{ 0.0, (double)g_settings.verticalOffset, 0.0, 0.0 });
    }
    rootContainer.VerticalAlignment(wux::VerticalAlignment::Center);

    wuxc::StackPanel verticalLayout;
    verticalLayout.Orientation(wuxc::Orientation::Vertical);
    verticalLayout.HorizontalAlignment(wux::HorizontalAlignment::Center);

    // Flip Clock Cards Panel (Hour and Minute)
    wuxc::StackPanel cardsLayout;
    cardsLayout.Orientation(wuxc::Orientation::Horizontal);
    cardsLayout.HorizontalAlignment(wux::HorizontalAlignment::Center);
    cardsLayout.Spacing(18.0);

    double cardWidth = g_settings.clockFontSize * 1.65;
    double cardHeight = g_settings.clockFontSize * 1.95;
    double cornerRad = (double)g_settings.cardCornerRadius;

    // --- HOUR CARD ---
    wuxc::Grid hourCard;
    hourCard.Width(cardWidth);
    hourCard.Height(cardHeight);

    // Acrylic / Liquid Glass Background
    wuxc::Border hourBackplate;
    hourBackplate.Background(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb((uint8_t)g_settings.glassOpacity, 255, 255, 255)));
    hourBackplate.BorderBrush(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(80, 255, 255, 255)));
    hourBackplate.BorderThickness(wux::Thickness{ 1.5, 1.5, 1.5, 1.5 });
    hourBackplate.CornerRadius(wux::CornerRadiusHelper::FromUniformRadius(cornerRad));

    // Center Flip Fold / Seam Line
    wuxs::Rectangle hourDivider;
    hourDivider.Height(2.0);
    hourDivider.HorizontalAlignment(wux::HorizontalAlignment::Stretch);
    hourDivider.VerticalAlignment(wux::VerticalAlignment::Center);
    hourDivider.Fill(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(45, 0, 0, 0)));
    hourDivider.Margin(wux::Thickness{ 6.0, 0.0, 6.0, 0.0 });

    // Hour Text
    wuxc::TextBlock hourText;
    hourText.Name(L"WindhawkFlipHourText");
    hourText.FontSize((double)g_settings.clockFontSize);
    hourText.FontFamily(wuxm::FontFamily(L"Segoe UI Variable Display"));
    hourText.FontWeight(winrt::Windows::UI::Text::FontWeights::Bold());
    hourText.Foreground(wuxm::SolidColorBrush(wu::Colors::White()));
    hourText.HorizontalAlignment(wux::HorizontalAlignment::Center);
    hourText.VerticalAlignment(wux::VerticalAlignment::Center);

    hourCard.Children().Append(hourBackplate);
    hourCard.Children().Append(hourDivider);
    hourCard.Children().Append(hourText);
    g_hourTextBlock = hourText;

    // --- MINUTE CARD ---
    wuxc::Grid minCard;
    minCard.Width(cardWidth);
    minCard.Height(cardHeight);

    // Acrylic / Liquid Glass Background
    wuxc::Border minBackplate;
    minBackplate.Background(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb((uint8_t)g_settings.glassOpacity, 255, 255, 255)));
    minBackplate.BorderBrush(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(80, 255, 255, 255)));
    minBackplate.BorderThickness(wux::Thickness{ 1.5, 1.5, 1.5, 1.5 });
    minBackplate.CornerRadius(wux::CornerRadiusHelper::FromUniformRadius(cornerRad));

    // Center Flip Fold / Seam Line
    wuxs::Rectangle minDivider;
    minDivider.Height(2.0);
    minDivider.HorizontalAlignment(wux::HorizontalAlignment::Stretch);
    minDivider.VerticalAlignment(wux::VerticalAlignment::Center);
    minDivider.Fill(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(45, 0, 0, 0)));
    minDivider.Margin(wux::Thickness{ 6.0, 0.0, 6.0, 0.0 });

    // Minute Text
    wuxc::TextBlock minText;
    minText.Name(L"WindhawkFlipMinText");
    minText.FontSize((double)g_settings.clockFontSize);
    minText.FontFamily(wuxm::FontFamily(L"Segoe UI Variable Display"));
    minText.FontWeight(winrt::Windows::UI::Text::FontWeights::Bold());
    minText.Foreground(wuxm::SolidColorBrush(wu::Colors::White()));
    minText.HorizontalAlignment(wux::HorizontalAlignment::Center);
    minText.VerticalAlignment(wux::VerticalAlignment::Center);

    minCard.Children().Append(minBackplate);
    minCard.Children().Append(minDivider);
    minCard.Children().Append(minText);
    g_minTextBlock = minText;

    cardsLayout.Children().Append(hourCard);
    cardsLayout.Children().Append(minCard);
    verticalLayout.Children().Append(cardsLayout);

    // --- DATE CAPSULE ---
    if (g_settings.showDateCapsule) {
        wuxc::Border dateCapsule;
        dateCapsule.Background(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(35, 255, 255, 255)));
        dateCapsule.BorderBrush(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(60, 255, 255, 255)));
        dateCapsule.BorderThickness(wux::Thickness{ 1.0, 1.0, 1.0, 1.0 });
        dateCapsule.CornerRadius(wux::CornerRadiusHelper::FromUniformRadius(12.0));
        dateCapsule.Padding(wux::Thickness{ 20.0, 8.0, 20.0, 8.0 });
        dateCapsule.Margin(wux::Thickness{ 0.0, 16.0, 0.0, 0.0 });
        dateCapsule.HorizontalAlignment(wux::HorizontalAlignment::Center);

        wuxc::TextBlock dateText;
        dateText.Name(L"WindhawkFlipDateText");
        dateText.FontSize(18.0);
        dateText.FontFamily(wuxm::FontFamily(L"Segoe UI Variable Text"));
        dateText.FontWeight(winrt::Windows::UI::Text::FontWeights::SemiBold());
        dateText.Foreground(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(240, 255, 255, 255)));
        dateText.HorizontalAlignment(wux::HorizontalAlignment::Center);

        dateCapsule.Child(dateText);
        verticalLayout.Children().Append(dateCapsule);
        g_dateTextBlock = dateText;
    }

    rootContainer.Children().Append(verticalLayout);

    // Initial time update
    UpdateTimeAndDate();

    // Live Timer (DispatcherTimer)
    g_clockTimer = wux::DispatcherTimer();
    g_clockTimer.Interval(std::chrono::milliseconds(500));
    g_clockTimer.Tick([](auto&&, auto&&) {
        UpdateTimeAndDate();
    });
    g_clockTimer.Start();

    return rootContainer;
}

// Visual Tree Watcher (IVisualTreeServiceCallback2)
class VisualTreeWatcher : public winrt::implements<VisualTreeWatcher, IVisualTreeServiceCallback2, winrt::non_agile>
{
public:
    VisualTreeWatcher(winrt::com_ptr<IUnknown> site) :
        m_XamlDiagnostics(site.as<IXamlDiagnostics>())
    {
        Wh_Log(L"Initializing VisualTreeWatcher...");

        HANDLE thread = CreateThread(
            nullptr, 0,
            [](LPVOID lpParam) -> DWORD {
                auto watcher = reinterpret_cast<VisualTreeWatcher*>(lpParam);
                HRESULT hr = watcher->m_XamlDiagnostics.as<IVisualTreeService3>()->AdviseVisualTreeChange(watcher);
                watcher->Release();
                if (FAILED(hr)) {
                    Wh_Log(L"AdviseVisualTreeChange failed: %08X", hr);
                } else {
                    Wh_Log(L"AdviseVisualTreeChange succeeded.");
                }
                return 0;
            },
            this, 0, nullptr);
        if (thread) {
            AddRef();
            CloseHandle(thread);
        }
    }

    ~VisualTreeWatcher() {
        Wh_Log(L"VisualTreeWatcher destroyed.");
    }

    void Unadvise() {
        if (m_XamlDiagnostics) {
            m_XamlDiagnostics.as<IVisualTreeService3>()->UnadviseVisualTreeChange(this);
        }
    }

private:
    HRESULT STDMETHODCALLTYPE OnVisualTreeChange(ParentChildRelation relation, VisualElement element, VisualMutationType mutationType) override try
    {
        if (mutationType == Add)
        {
            winrt::Windows::Foundation::IInspectable obj;
            HRESULT hr = m_XamlDiagnostics->GetIInspectableFromHandle(element.Handle, reinterpret_cast<::IInspectable**>(winrt::put_abi(obj)));
            if (SUCCEEDED(hr) && obj)
            {
                auto frameworkElement = obj.try_as<wux::FrameworkElement>();
                if (frameworkElement)
                {
                    std::wstring name = frameworkElement.Name().c_str();

                    // 1. Lock Screen Root Grid: LockRootGrid
                    if ((name == L"LockRootGrid" || name == L"MainPageContainer") && !g_flipClockInjected)
                    {
                        auto grid = frameworkElement.try_as<wuxc::Grid>();
                        if (grid)
                        {
                            Wh_Log(L"Found lock screen root grid: %s. Injecting Flip Clock...", name.c_str());
                            if (g_settings.clockStyle != L"defaultOnly")
                            {
                                auto flipClock = BuildFlipClockElement();
                                grid.Children().Append(flipClock);
                                g_flipClockInjected = true;
                                Wh_Log(L"Flip Clock successfully injected!");
                            }
                        }
                    }

                    // 2. Default Time & Date Panel: TimeAndDatePanel
                    if (name == L"TimeAndDatePanel" || name == L"Time" || name == L"Date")
                    {
                        if (g_settings.hideDefaultClock && g_settings.clockStyle != L"defaultOnly")
                        {
                            Wh_Log(L"Hiding default clock/date element: %s", name.c_str());
                            frameworkElement.Visibility(wux::Visibility::Collapsed);
                        }
                    }

                    // 3. Default Widget / Weather Panels
                    if (name == L"AdaptiveCardDetailContainer" || name == L"DetailTextPanel" || name == L"LockWidgetCanvas")
                    {
                        if (g_settings.hideDefaultWidgets)
                        {
                            Wh_Log(L"Hiding lock screen widget/weather area: %s", name.c_str());
                            frameworkElement.Visibility(wux::Visibility::Collapsed);
                        }
                    }
                }
            }
        }
        return S_OK;
    }
    catch (...)
    {
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE OnElementStateChanged(InstanceHandle, VisualElementState, LPCWSTR) noexcept override
    {
        return S_OK;
    }

    winrt::com_ptr<IXamlDiagnostics> m_XamlDiagnostics{ nullptr };
};

winrt::com_ptr<VisualTreeWatcher> g_visualTreeWatcher{ nullptr };

// {C85D8CC7-5463-40E8-A432-F5916B6427E5}
static constexpr CLSID CLSID_WindhawkTAP = { 0xc85d8cc7, 0x5463, 0x40e8, { 0xa4, 0x32, 0xf5, 0x91, 0x6b, 0x64, 0x27, 0xe5 } };

class WindhawkTAP : public winrt::implements<WindhawkTAP, IObjectWithSite, winrt::non_agile>
{
public:
    HRESULT STDMETHODCALLTYPE SetSite(IUnknown *pUnkSite) override try
    {
        if (g_visualTreeWatcher) {
            g_visualTreeWatcher->Unadvise();
            g_visualTreeWatcher = nullptr;
        }

        site.copy_from(pUnkSite);

        if (site) {
            HMODULE hSelf = nullptr;
            GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                               (LPCWSTR)&LoadSettings, &hSelf);
            if (hSelf) {
                FreeLibrary(hSelf);
            }
            g_visualTreeWatcher = winrt::make_self<VisualTreeWatcher>(site);
        }
        return S_OK;
    }
    catch (...) {
        return winrt::to_hresult();
    }

    HRESULT STDMETHODCALLTYPE GetSite(REFIID riid, void **ppvSite) noexcept override {
        return site.as(riid, ppvSite);
    }

private:
    winrt::com_ptr<IUnknown> site;
};

template<class T>
struct SimpleFactory : winrt::implements<SimpleFactory<T>, IClassFactory, winrt::non_agile>
{
    HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppvObject) override try
    {
        if (!pUnkOuter) {
            *ppvObject = nullptr;
            return winrt::make<T>().as(riid, ppvObject);
        }
        return CLASS_E_NOAGGREGATION;
    }
    catch (...) {
        return winrt::to_hresult();
    }

    HRESULT STDMETHODCALLTYPE LockServer(BOOL) noexcept override {
        return S_OK;
    }
};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdll-attribute-on-redeclaration"

__declspec(dllexport)
_Use_decl_annotations_ STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv) try
{
    if (rclsid == CLSID_WindhawkTAP) {
        *ppv = nullptr;
        return winrt::make<SimpleFactory<WindhawkTAP>>().as(riid, ppv);
    }
    return CLASS_E_CLASSNOTAVAILABLE;
}
catch (...) {
    return winrt::to_hresult();
}

__declspec(dllexport)
_Use_decl_annotations_ STDAPI DllCanUnloadNow(void) {
    if (winrt::get_module_lock()) {
        return S_FALSE;
    }
    return S_OK;
}

#pragma clang diagnostic pop

HMODULE GetCurrentModuleHandle() {
    HMODULE module = nullptr;
    GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                           GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                       (LPCWSTR)&GetCurrentModuleHandle, &module);
    return module;
}

using PFN_INITIALIZE_XAML_DIAGNOSTICS_EX = decltype(&InitializeXamlDiagnosticsEx);

std::atomic<bool> g_tapInjected = false;

HRESULT InjectWindhawkTAP() noexcept
{
    if (g_tapInjected.exchange(true)) {
        return S_OK; // Already injected
    }

    HMODULE module = GetCurrentModuleHandle();
    if (!module) {
        Wh_Log(L"GetCurrentModuleHandle failed: %u", GetLastError());
        g_tapInjected = false;
        return HRESULT_FROM_WIN32(GetLastError());
    }

    WCHAR location[MAX_PATH];
    if (GetModuleFileNameW(module, location, ARRAYSIZE(location)) == 0) {
        Wh_Log(L"GetModuleFileNameW failed: %u", GetLastError());
        g_tapInjected = false;
        return HRESULT_FROM_WIN32(GetLastError());
    }

    const HMODULE wux = LoadLibraryExW(L"Windows.UI.Xaml.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (!wux) {
        Wh_Log(L"Failed to load Windows.UI.Xaml.dll: %u", GetLastError());
        g_tapInjected = false;
        return HRESULT_FROM_WIN32(GetLastError());
    }

    const auto ixde = reinterpret_cast<PFN_INITIALIZE_XAML_DIAGNOSTICS_EX>(
        GetProcAddress(wux, "InitializeXamlDiagnosticsEx"));
    if (!ixde) {
        Wh_Log(L"InitializeXamlDiagnosticsEx export not found!");
        g_tapInjected = false;
        return HRESULT_FROM_WIN32(GetLastError());
    }

    Wh_Log(L"Starting InitializeXamlDiagnosticsEx connection loop (TAP DLL: %s)...", location);
    
    HRESULT hr = E_FAIL;
    for (int i = 0; i < 10000; i++)
    {
        WCHAR connectionName[256];
        wsprintfW(connectionName, L"VisualDiagConnection%d", i + 1);

        hr = ixde(connectionName, GetCurrentProcessId(), L"", location, CLSID_WindhawkTAP, nullptr);
        if (hr != HRESULT_FROM_WIN32(ERROR_NOT_FOUND))
        {
            Wh_Log(L"InitializeXamlDiagnosticsEx successfully connected! (%s, hr=%08X)", connectionName, hr);
            return hr;
        }
    }

    Wh_Log(L"InitializeXamlDiagnosticsEx failed across all connection names (hr=%08X)", hr);
    g_tapInjected = false;
    return hr;
}

// Window Creation Hooks (Catching CoreWindow)
void CheckAndInjectForWindow(HWND hWnd, LPCWSTR lpClassName, PCSTR sourceFunc) {
    if (!hWnd || !lpClassName) return;

    BOOL bTextual = ((ULONG_PTR)lpClassName & ~(ULONG_PTR)0xffff) != 0;
    if (bTextual && _wcsicmp(lpClassName, L"Windows.UI.Core.CoreWindow") == 0) {
        Wh_Log(L"CoreWindow detected: %08X (Source: %S). Injecting TAP...", (DWORD)(ULONG_PTR)hWnd, sourceFunc);
        InjectWindhawkTAP();
    }
}

using CreateWindowExW_t = decltype(&CreateWindowExW);
CreateWindowExW_t CreateWindowExW_Original;
HWND WINAPI CreateWindowExW_Hook(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle,
                                int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu,
                                HINSTANCE hInstance, LPVOID lpParam)
{
    HWND hWnd = CreateWindowExW_Original(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
    if (hWnd) {
        CheckAndInjectForWindow(hWnd, lpClassName, __FUNCTION__);
    }
    return hWnd;
}

using CreateWindowInBand_t = HWND(WINAPI*)(DWORD, LPCWSTR, LPCWSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, PVOID, DWORD);
CreateWindowInBand_t CreateWindowInBand_Original;
HWND WINAPI CreateWindowInBand_Hook(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle,
                                    int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu,
                                    HINSTANCE hInstance, PVOID lpParam, DWORD dwBand)
{
    HWND hWnd = CreateWindowInBand_Original(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam, dwBand);
    if (hWnd) {
        CheckAndInjectForWindow(hWnd, lpClassName, __FUNCTION__);
    }
    return hWnd;
}

using CreateWindowInBandEx_t = HWND(WINAPI*)(DWORD, LPCWSTR, LPCWSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, PVOID, DWORD, DWORD);
CreateWindowInBandEx_t CreateWindowInBandEx_Original;
HWND WINAPI CreateWindowInBandEx_Hook(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle,
                                      int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu,
                                      HINSTANCE hInstance, PVOID lpParam, DWORD dwBand, DWORD dwTypeFlags)
{
    HWND hWnd = CreateWindowInBandEx_Original(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam, dwBand, dwTypeFlags);
    if (hWnd) {
        CheckAndInjectForWindow(hWnd, lpClassName, __FUNCTION__);
    }
    return hWnd;
}

// Library Load Hook (Catching Windows.UI.Xaml.dll readiness)
using LoadLibraryExW_t = decltype(&LoadLibraryExW);
LoadLibraryExW_t LoadLibraryExW_Original;
HMODULE WINAPI LoadLibraryExW_Hook(LPCWSTR lpLibFileName, HANDLE hFile, DWORD dwFlags)
{
    HMODULE module = LoadLibraryExW_Original(lpLibFileName, hFile, dwFlags);
    if (module && lpLibFileName) {
        if (wcsstr(lpLibFileName, L"Windows.UI.Xaml.dll") || wcsstr(lpLibFileName, L"windows.ui.xaml.dll")) {
            Wh_Log(L"Windows.UI.Xaml.dll loaded, initiating TAP injection...");
            InjectWindhawkTAP();
        }
    }
    return module;
}

// Enumerate existing CoreWindow instances
void SearchExistingCoreWindows() {
    EnumWindows([](HWND hWnd, LPARAM) -> BOOL {
        DWORD pid = 0;
        GetWindowThreadProcessId(hWnd, &pid);
        if (pid == GetCurrentProcessId()) {
            WCHAR clsName[64];
            if (GetClassNameW(hWnd, clsName, ARRAYSIZE(clsName)) > 0) {
                if (_wcsicmp(clsName, L"Windows.UI.Core.CoreWindow") == 0) {
                    Wh_Log(L"Existing CoreWindow found: %08X", (DWORD)(ULONG_PTR)hWnd);
                    InjectWindhawkTAP();
                    return FALSE;
                }
            }
        }
        return TRUE;
    }, 0);
}

// Windhawk Lifecycle Functions
BOOL Wh_ModInit() {
    Wh_Log(L"Windows 11 Lock Screen Mod initializing (Wh_ModInit)...");

    LoadSettings();

    // Hook window creation APIs
    Wh_SetFunctionHook((void*)CreateWindowExW,
                       (void*)CreateWindowExW_Hook,
                       (void**)&CreateWindowExW_Original);

    HMODULE user32Module = LoadLibraryExW(L"user32.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (user32Module) {
        void* pCreateWindowInBand = (void*)GetProcAddress(user32Module, "CreateWindowInBand");
        if (pCreateWindowInBand) {
            Wh_SetFunctionHook(pCreateWindowInBand,
                               (void*)CreateWindowInBand_Hook,
                               (void**)&CreateWindowInBand_Original);
        }

        void* pCreateWindowInBandEx = (void*)GetProcAddress(user32Module, "CreateWindowInBandEx");
        if (pCreateWindowInBandEx) {
            Wh_SetFunctionHook(pCreateWindowInBandEx,
                               (void*)CreateWindowInBandEx_Hook,
                               (void**)&CreateWindowInBandEx_Original);
        }
    }

    // Windows.UI.Xaml.dll loading hook
    HMODULE kernelBase = GetModuleHandleW(L"kernelbase.dll");
    if (kernelBase) {
        auto pLoadLibraryExW = (LoadLibraryExW_t)GetProcAddress(kernelBase, "LoadLibraryExW");
        if (pLoadLibraryExW) {
            Wh_SetFunctionHook((void*)pLoadLibraryExW,
                               (void*)LoadLibraryExW_Hook,
                               (void**)&LoadLibraryExW_Original);
        }
    }

    // If Windows.UI.Xaml.dll is already loaded, check directly
    if (GetModuleHandleW(L"Windows.UI.Xaml.dll")) {
        Wh_Log(L"Windows.UI.Xaml.dll already loaded.");
        SearchExistingCoreWindows();
    }

    return TRUE;
}

void Wh_ModAfterInit() {
    Wh_Log(L"Wh_ModAfterInit: Scanning for existing windows...");
    SearchExistingCoreWindows();
}

void Wh_ModUninit() {
    Wh_Log(L"Windows 11 Lock Screen Mod uninitializing (Wh_ModUninit)...");
    if (g_clockTimer) {
        g_clockTimer.Stop();
        g_clockTimer = nullptr;
    }
    if (g_visualTreeWatcher) {
        g_visualTreeWatcher->Unadvise();
        g_visualTreeWatcher = nullptr;
    }
    g_tapInjected = false;
    g_flipClockInjected = false;
}

void Wh_ModSettingsChanged() {
    Wh_Log(L"Mod settings changed (Wh_ModSettingsChanged)...");
    LoadSettings();
    UpdateTimeAndDate();
}

