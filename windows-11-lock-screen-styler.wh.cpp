// ==WindhawkMod==
// @id              windows-11-lock-screen-styler
// @name            Windows 11 Lock Screen Styler
// @name:tr-TR      Windows 11 Kilit Ekranı Özelleştirici
// @description     Customize the Windows 11 lock screen with modern clock styles, date display, and widget controls.
// @description:tr-TR Windows 11 kilit ekranını modern saat stilleri, tarih göstergesi ve widget denetimleriyle özelleştirin.
// @version         0.2.0
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
- **Modern Flip Clock:** Split glass cards for hour, minute, and optional seconds with an elegant horizontal flip seam.
- **Retro Vintage Flip Clock:** Classic mechanical Solari-inspired flip clock with matte charcoal flap cards, aged ivory cream typography, mechanical split seam, and hinge axle clips.
- **Cyberpunk / Neon Glow Clock:** High-voltage cyberpunk aesthetic with dark obsidian acrylic cards, electric cyan neon edge highlights, laser-cut split seam, and hot magenta HUD date capsule.
- **Retro Pixel / LED Dot Matrix Clock:** Authentic dot matrix display inspired by classic digital boards with active and ambient inactive LED dots.
- **Minimalist Digital Clock:** Clean, elegant typography with smooth date indicators.
- **Show Seconds Toggle:** Optional live seconds display for both Flip and Pixel clock styles.
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
  $name:tr-TR: "Saat Tasarım Stili"
  $description: "The clock style to display on the lock screen."
  $description:tr-TR: "Kilit ekranında görüntülenecek saat stili."
  $options:
    - flip: "Frosted Glass Flip Clock"
    - flip:tr-TR: "Buzlu Cam Flip Saat"
    - vintage: "Retro Vintage Flip Clock"
    - vintage:tr-TR: "Retro Vintage Flip Saat"
    - cyberpunk: "Cyberpunk / Neon Glow Clock"
    - cyberpunk:tr-TR: "Cyberpunk / Neon Glow Saat"
    - pixel: "Retro Pixel / LED Dot Matrix Clock"
    - pixel:tr-TR: "Retro Piksel / LED Matris Saat"
    - minimal: "Minimalist Digital Clock"
    - minimal:tr-TR: "Minimalist Dijital Saat"
    - defaultOnly: "Default Clock Only (Widgets Hidden)"
    - defaultOnly:tr-TR: "Yalnızca Varsayılan Saat (Widget'lar Gizli)"
- showSeconds: false
  $name: "Show Seconds"
  $name:tr-TR: "Saniyeyi Göster"
  $description: "Displays seconds on the clock."
  $description:tr-TR: "Saatte saniye göstergesini etkinleştirir."
- glassOpacity: 45
  $name: "Glass Opacity (Liquid Glass Alpha)"
  $name:tr-TR: "Cam Opaklığı (Alfa Değeri)"
  $description: "Translucency level of the flip cards (0 to 255; 0 is completely transparent, 255 is fully opaque)."
  $description:tr-TR: "Flip kartlarının yarı saydamlık derecesi (0 ile 255 arası; 0 tamamen saydam, 255 tam opak)."
- cardCornerRadius: 22
  $name: "Card Corner Radius (px)"
  $name:tr-TR: "Kart Köşe Yuvarlaklığı (px)"
  $description: "Corner curvature radius of the flip clock cards."
  $description:tr-TR: "Flip saat kartlarının köşe kavis yarıçapı."
- clockFontSize: 92
  $name: "Digit Font Size"
  $name:tr-TR: "Rakam Font Boyutu"
  $description: "Font size for hour and minute digits."
  $description:tr-TR: "Saat ve dakika rakamlarının punto büyüklüğü."
- verticalOffset: 0
  $name: "Vertical Offset (px)"
  $name:tr-TR: "Dikey Konum Ofseti (px)"
  $description: "Offset to shift the clock vertically up or down (-200 to +400)."
  $description:tr-TR: "Saatin ekrandaki dikey konumunu yukarı veya aşağı kaydırma ofseti (-200 ile +400 arası)."
- clockAlignment: center
  $name: "Clock Horizontal Alignment"
  $name:tr-TR: "Saat Yatay Hizalaması"
  $description: "Horizontal alignment of the clock on screen."
  $description:tr-TR: "Saatin ekrandaki yatay hizalaması."
  $options:
    - center: "Center of Screen"
    - left: "Left Side"
    - right: "Right Side"
- hideDefaultWidgets: true
  $name: "Hide Default Widgets"
  $name:tr-TR: "Varsayılan Widget'ları Gizle"
  $description: "Hides MSN weather, sports, and news widget areas on the lock screen."
  $description:tr-TR: "Kilit ekranındaki MSN hava durumu, spor ve haber widget alanını gizler."
- hideDefaultClock: true
  $name: "Hide Default Lock Screen Clock"
  $name:tr-TR: "Varsayılan Kilit Ekranı Saatini Gizle"
  $description: "Hides the default Windows 11 clock and date text to make way for the new clock."
  $description:tr-TR: "Windows 11'in standart saat ve tarih metnini gizleyerek yeni saatin görünmesini sağlar."
- showDateCapsule: true
  $name: "Show Date Capsule"
  $name:tr-TR: "Tarih Kapsülünü Göster"
  $description: "Displays a date and weekday capsule below the flip clock cards."
  $description:tr-TR: "Flip saat kartlarının altında gün ve ay kapsülünü görüntüler."
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
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.UI.Text.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.Media.h>
#include <winrt/Windows.UI.Xaml.Shapes.h>
#include <string>
#include <vector>
#include <chrono>

namespace wux = winrt::Windows::UI::Xaml;
namespace wuxc = winrt::Windows::UI::Xaml::Controls;
namespace wuxm = winrt::Windows::UI::Xaml::Media;
namespace wuxs = winrt::Windows::UI::Xaml::Shapes;
namespace wu = winrt::Windows::UI;

// Mod Configuration Settings
struct ModSettings {
    std::wstring clockStyle;
    bool showSeconds;
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

    g_settings.showSeconds = Wh_GetIntSetting(L"showSeconds") != 0;

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

    Wh_Log(L"Settings loaded: style=%s, showSec=%d, opacity=%d, font=%d, hideWidgets=%d, hideClock=%d",
           g_settings.clockStyle.c_str(), g_settings.showSeconds, g_settings.glassOpacity,
           g_settings.clockFontSize, g_settings.hideDefaultWidgets, g_settings.hideDefaultClock);
}

// UI State References
wuxc::Grid g_lockRootGrid{ nullptr };
wux::UIElement g_activeClockElement{ nullptr };
wuxc::TextBlock g_hourTextBlock{ nullptr };
wuxc::TextBlock g_minTextBlock{ nullptr };
wuxc::TextBlock g_secTextBlock{ nullptr };
wuxc::TextBlock g_minimalTimeTextBlock{ nullptr };
wuxc::TextBlock g_dateTextBlock{ nullptr };
wux::DispatcherTimer g_clockTimer{ nullptr };
bool g_clockInjected = false;

// 7x9 Dot Matrix Font Table for Digits 0 to 9 with 2-Dot Stroke Thickness
// Each digit consists of 9 rows; each row uses the lower 7 bits (bit 6 = col 0, bit 0 = col 6).
static const uint8_t FONT_7x9[10][9] = {
    // 0
    { 0b0111110,
      0b1111111,
      0b1100011,
      0b1100011,
      0b1100011,
      0b1100011,
      0b1100011,
      0b1111111,
      0b0111110 },
    // 1
    { 0b0011100,
      0b0111100,
      0b0001100,
      0b0001100,
      0b0001100,
      0b0001100,
      0b0001100,
      0b0111110,
      0b0111110 },
    // 2
    { 0b0111110,
      0b1111111,
      0b0000011,
      0b0000011,
      0b0111111,
      0b1111110,
      0b1100000,
      0b1111111,
      0b1111111 },
    // 3
    { 0b0111110,
      0b1111111,
      0b0000011,
      0b0000011,
      0b0011110,
      0b0000011,
      0b0000011,
      0b1111111,
      0b0111110 },
    // 4
    { 0b1100011,
      0b1100011,
      0b1100011,
      0b1100011,
      0b1111111,
      0b1111111,
      0b0000011,
      0b0000011,
      0b0000011 },
    // 5
    { 0b1111111,
      0b1111111,
      0b1100000,
      0b1111110,
      0b1111111,
      0b0000011,
      0b0000011,
      0b1111111,
      0b0111110 },
    // 6
    { 0b0111110,
      0b1111111,
      0b1100000,
      0b1111110,
      0b1111111,
      0b1100011,
      0b1100011,
      0b1111111,
      0b0111110 },
    // 7
    { 0b1111111,
      0b1111111,
      0b0000011,
      0b0000110,
      0b0001100,
      0b0011000,
      0b0110000,
      0b0110000,
      0b0110000 },
    // 8
    { 0b0111110,
      0b1111111,
      0b1100011,
      0b1100011,
      0b0111110,
      0b1100011,
      0b1100011,
      0b1111111,
      0b0111110 },
    // 9
    { 0b0111110,
      0b1111111,
      0b1100011,
      0b1100011,
      0b1111111,
      0b0111111,
      0b0000011,
      0b1111111,
      0b0111110 }
};

// Pixel Clock State
struct PixelDigitGrid {
    std::vector<wuxs::Ellipse> dots; // 63 dots per digit (7 cols x 9 rows)
};
PixelDigitGrid g_pixelDigits[6]; // H1, H2, M1, M2, S1, S2
wuxm::SolidColorBrush g_brushActiveDot{ nullptr };
wuxm::SolidColorBrush g_brushInactiveDot{ nullptr };

// Helper to apply root horizontal and vertical alignments
void ApplyAlignmentAndMargin(wuxc::Grid& rootContainer) {
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
}

// Update single pixel digit dots (7x9 matrix)
void SetPixelDigitValue(PixelDigitGrid& digitRef, int val) {
    if (val < 0 || val > 9 || digitRef.dots.size() != 63 || !g_brushActiveDot || !g_brushInactiveDot) {
        return;
    }
    const uint8_t* rows = FONT_7x9[val];
    for (int r = 0; r < 9; r++) {
        uint8_t rowBits = rows[r];
        for (int c = 0; c < 7; c++) {
            bool active = (rowBits & (1 << (6 - c))) != 0;
            int idx = r * 7 + c;
            digitRef.dots[idx].Fill(active ? g_brushActiveDot : g_brushInactiveDot);
        }
    }
}

// Update Time and Date
void UpdateTimeAndDate() {
    SYSTEMTIME st;
    GetLocalTime(&st);

    if (g_settings.clockStyle == L"pixel") {
        int h1 = st.wHour / 10;
        int h2 = st.wHour % 10;
        int m1 = st.wMinute / 10;
        int m2 = st.wMinute % 10;

        SetPixelDigitValue(g_pixelDigits[0], h1);
        SetPixelDigitValue(g_pixelDigits[1], h2);
        SetPixelDigitValue(g_pixelDigits[2], m1);
        SetPixelDigitValue(g_pixelDigits[3], m2);

        if (g_settings.showSeconds) {
            int s1 = st.wSecond / 10;
            int s2 = st.wSecond % 10;
            SetPixelDigitValue(g_pixelDigits[4], s1);
            SetPixelDigitValue(g_pixelDigits[5], s2);
        }
    } else if (g_settings.clockStyle == L"minimal") {
        if (g_minimalTimeTextBlock) {
            WCHAR timeBuf[32];
            if (g_settings.showSeconds) {
                swprintf_s(timeBuf, L"%02d:%02d:%02d", st.wHour, st.wMinute, st.wSecond);
            } else {
                swprintf_s(timeBuf, L"%02d:%02d", st.wHour, st.wMinute);
            }
            g_minimalTimeTextBlock.Text(timeBuf);
        }
    } else {
        // Flip Clock
        if (g_hourTextBlock && g_minTextBlock) {
            WCHAR hourBuf[8];
            swprintf_s(hourBuf, L"%02d", st.wHour);
            WCHAR minBuf[8];
            swprintf_s(minBuf, L"%02d", st.wMinute);

            g_hourTextBlock.Text(hourBuf);
            g_minTextBlock.Text(minBuf);

            if (g_secTextBlock && g_settings.showSeconds) {
                WCHAR secBuf[8];
                swprintf_s(secBuf, L"%02d", st.wSecond);
                g_secTextBlock.Text(secBuf);
            }
        }
    }

    if (g_dateTextBlock && g_settings.showDateCapsule) {
        WCHAR dateBuf[128];
        if (GetDateFormatW(LOCALE_USER_DEFAULT, DATE_LONGDATE, &st, nullptr, dateBuf, ARRAYSIZE(dateBuf)) > 0) {
            g_dateTextBlock.Text(dateBuf);
        }
    }
}

// Start Live Clock Timer
void StartClockTimer() {
    if (g_clockTimer) {
        g_clockTimer.Stop();
        g_clockTimer = nullptr;
    }
    g_clockTimer = wux::DispatcherTimer();
    g_clockTimer.Interval(std::chrono::milliseconds(500));
    g_clockTimer.Tick([](auto&&, auto&&) {
        UpdateTimeAndDate();
    });
    g_clockTimer.Start();
}

// Build Single Flip Card Element
wuxc::Grid CreateFlipCard(double width, double height, double cornerRadius, wuxc::TextBlock& outText, const wchar_t* textName) {
    wuxc::Grid card;
    card.Width(width);
    card.Height(height);

    // Acrylic Backplate
    wuxc::Border backplate;
    backplate.Background(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb((uint8_t)g_settings.glassOpacity, 255, 255, 255)));
    backplate.BorderBrush(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(80, 255, 255, 255)));
    backplate.BorderThickness(wux::Thickness{ 1.5, 1.5, 1.5, 1.5 });
    backplate.CornerRadius(wux::CornerRadiusHelper::FromUniformRadius(cornerRadius));

    // Center Flip Fold / Seam Line
    wuxs::Rectangle divider;
    divider.Height(2.0);
    divider.HorizontalAlignment(wux::HorizontalAlignment::Stretch);
    divider.VerticalAlignment(wux::VerticalAlignment::Center);
    divider.Fill(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(45, 0, 0, 0)));
    divider.Margin(wux::Thickness{ 6.0, 0.0, 6.0, 0.0 });

    // Card Text
    wuxc::TextBlock cardText;
    cardText.Name(textName);
    cardText.FontSize((double)g_settings.clockFontSize);
    cardText.FontFamily(wuxm::FontFamily(L"Segoe UI Variable Display"));
    cardText.FontWeight(winrt::Windows::UI::Text::FontWeights::Bold());
    cardText.Foreground(wuxm::SolidColorBrush(wu::Colors::White()));
    cardText.HorizontalAlignment(wux::HorizontalAlignment::Center);
    cardText.VerticalAlignment(wux::VerticalAlignment::Center);

    card.Children().Append(backplate);
    card.Children().Append(divider);
    card.Children().Append(cardText);
    outText = cardText;

    return card;
}

// Build Flip Clock UI Element
wux::UIElement BuildFlipClockElement() {
    wuxc::Grid rootContainer;
    rootContainer.Name(L"WindhawkFlipClockContainer");
    ApplyAlignmentAndMargin(rootContainer);

    wuxc::StackPanel verticalLayout;
    verticalLayout.Orientation(wuxc::Orientation::Vertical);
    verticalLayout.HorizontalAlignment(wux::HorizontalAlignment::Center);

    wuxc::StackPanel cardsLayout;
    cardsLayout.Orientation(wuxc::Orientation::Horizontal);
    cardsLayout.HorizontalAlignment(wux::HorizontalAlignment::Center);
    cardsLayout.Spacing(g_settings.showSeconds ? 14.0 : 18.0);

    double cardWidth = g_settings.showSeconds ? (g_settings.clockFontSize * 1.45) : (g_settings.clockFontSize * 1.65);
    double cardHeight = g_settings.clockFontSize * 1.95;
    double cornerRad = (double)g_settings.cardCornerRadius;

    // 1. Hour Card
    auto hourCard = CreateFlipCard(cardWidth, cardHeight, cornerRad, g_hourTextBlock, L"WindhawkFlipHourText");
    cardsLayout.Children().Append(hourCard);

    // 2. Minute Card
    auto minCard = CreateFlipCard(cardWidth, cardHeight, cornerRad, g_minTextBlock, L"WindhawkFlipMinText");
    cardsLayout.Children().Append(minCard);

    // 3. Seconds Card (If enabled)
    if (g_settings.showSeconds) {
        auto secCard = CreateFlipCard(cardWidth, cardHeight, cornerRad, g_secTextBlock, L"WindhawkFlipSecText");
        cardsLayout.Children().Append(secCard);
    }

    verticalLayout.Children().Append(cardsLayout);

    // Date Capsule
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
    UpdateTimeAndDate();
    StartClockTimer();

    return rootContainer;
}

// Build Single Vintage Flip Card Element (Retro Mechanical Airport/Station Solari Style)
wuxc::Grid CreateVintageFlipCard(double width, double height, double cornerRadius, wuxc::TextBlock& outText, const wchar_t* textName) {
    wuxc::Grid card;
    card.Width(width);
    card.Height(height);

    // Matte Industrial Charcoal Flap Body
    wuxc::Border flapBackplate;
    flapBackplate.Background(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(235, 18, 20, 24)));
    flapBackplate.BorderBrush(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(95, 60, 68, 78)));
    flapBackplate.BorderThickness(wux::Thickness{ 1.2, 1.2, 1.2, 1.2 });
    flapBackplate.CornerRadius(wux::CornerRadiusHelper::FromUniformRadius(cornerRadius));

    // Vintage Warm Cream / Aged Ivory Typography
    wuxc::TextBlock cardText;
    cardText.Name(textName);
    cardText.FontSize((double)g_settings.clockFontSize);
    cardText.FontFamily(wuxm::FontFamily(L"Segoe UI Variable Display"));
    cardText.FontWeight(winrt::Windows::UI::Text::FontWeights::ExtraBold());
    cardText.Foreground(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(255, 246, 241, 230)));
    cardText.HorizontalAlignment(wux::HorizontalAlignment::Center);
    cardText.VerticalAlignment(wux::VerticalAlignment::Center);

    // Center Mechanical Split: Upper shadow + Lower light catch bevel + Side axle hinge clips
    wuxc::Grid splitSeam;
    splitSeam.Height(10.0);
    splitSeam.HorizontalAlignment(wux::HorizontalAlignment::Stretch);
    splitSeam.VerticalAlignment(wux::VerticalAlignment::Center);

    wuxc::StackPanel seamLines;
    seamLines.Orientation(wuxc::Orientation::Vertical);
    seamLines.VerticalAlignment(wux::VerticalAlignment::Center);

    // Deep shadow groove between top and bottom flaps
    wuxs::Rectangle shadowGroove;
    shadowGroove.Height(2.0);
    shadowGroove.HorizontalAlignment(wux::HorizontalAlignment::Stretch);
    shadowGroove.Fill(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(250, 8, 9, 11)));
    shadowGroove.Margin(wux::Thickness{ 4.0, 0.0, 4.0, 0.0 });

    // Subtle edge highlight on bottom flap catching ambient overhead light
    wuxs::Rectangle bevelHighlight;
    bevelHighlight.Height(1.0);
    bevelHighlight.HorizontalAlignment(wux::HorizontalAlignment::Stretch);
    bevelHighlight.Fill(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(38, 255, 255, 255)));
    bevelHighlight.Margin(wux::Thickness{ 4.0, 0.0, 4.0, 0.0 });

    seamLines.Children().Append(shadowGroove);
    seamLines.Children().Append(bevelHighlight);
    splitSeam.Children().Append(seamLines);

    // Left and Right Axle Clips (Mechanical hinge pins)
    wuxs::Rectangle leftClip;
    leftClip.Width(4.0);
    leftClip.Height(9.0);
    leftClip.RadiusX(1.0);
    leftClip.RadiusY(1.0);
    leftClip.HorizontalAlignment(wux::HorizontalAlignment::Left);
    leftClip.VerticalAlignment(wux::VerticalAlignment::Center);
    leftClip.Fill(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(225, 10, 12, 15)));

    wuxs::Rectangle rightClip;
    rightClip.Width(4.0);
    rightClip.Height(9.0);
    rightClip.RadiusX(1.0);
    rightClip.RadiusY(1.0);
    rightClip.HorizontalAlignment(wux::HorizontalAlignment::Right);
    rightClip.VerticalAlignment(wux::VerticalAlignment::Center);
    rightClip.Fill(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(225, 10, 12, 15)));

    splitSeam.Children().Append(leftClip);
    splitSeam.Children().Append(rightClip);

    card.Children().Append(flapBackplate);
    card.Children().Append(cardText);
    card.Children().Append(splitSeam);
    outText = cardText;

    return card;
}

// Build Retro Vintage Flip Clock UI Element
wux::UIElement BuildVintageClockElement() {
    wuxc::Grid rootContainer;
    rootContainer.Name(L"WindhawkVintageClockContainer");
    ApplyAlignmentAndMargin(rootContainer);

    wuxc::StackPanel verticalLayout;
    verticalLayout.Orientation(wuxc::Orientation::Vertical);
    verticalLayout.HorizontalAlignment(wux::HorizontalAlignment::Center);

    wuxc::StackPanel cardsLayout;
    cardsLayout.Orientation(wuxc::Orientation::Horizontal);
    cardsLayout.HorizontalAlignment(wux::HorizontalAlignment::Center);
    cardsLayout.Spacing(g_settings.showSeconds ? 12.0 : 16.0);

    double cardWidth = g_settings.showSeconds ? (g_settings.clockFontSize * 1.42) : (g_settings.clockFontSize * 1.62);
    double cardHeight = g_settings.clockFontSize * 1.95;
    double cornerRad = 10.0;

    // 1. Hour Card
    auto hourCard = CreateVintageFlipCard(cardWidth, cardHeight, cornerRad, g_hourTextBlock, L"WindhawkVintageHourText");
    cardsLayout.Children().Append(hourCard);

    // 2. Minute Card
    auto minCard = CreateVintageFlipCard(cardWidth, cardHeight, cornerRad, g_minTextBlock, L"WindhawkVintageMinText");
    cardsLayout.Children().Append(minCard);

    // 3. Seconds Card (If enabled)
    if (g_settings.showSeconds) {
        auto secCard = CreateVintageFlipCard(cardWidth, cardHeight, cornerRad, g_secTextBlock, L"WindhawkVintageSecText");
        cardsLayout.Children().Append(secCard);
    }

    verticalLayout.Children().Append(cardsLayout);

    // Vintage Date Plate (Embossed Industrial Badge Style)
    if (g_settings.showDateCapsule) {
        wuxc::Border dateCapsule;
        dateCapsule.Background(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(215, 20, 22, 28)));
        dateCapsule.BorderBrush(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(85, 60, 68, 78)));
        dateCapsule.BorderThickness(wux::Thickness{ 1.0, 1.0, 1.0, 1.0 });
        dateCapsule.CornerRadius(wux::CornerRadiusHelper::FromUniformRadius(8.0));
        dateCapsule.Padding(wux::Thickness{ 22.0, 7.0, 22.0, 7.0 });
        dateCapsule.Margin(wux::Thickness{ 0.0, 18.0, 0.0, 0.0 });
        dateCapsule.HorizontalAlignment(wux::HorizontalAlignment::Center);

        wuxc::TextBlock dateText;
        dateText.Name(L"WindhawkVintageDateText");
        dateText.FontSize(18.0);
        dateText.FontFamily(wuxm::FontFamily(L"Segoe UI Variable Text"));
        dateText.FontWeight(winrt::Windows::UI::Text::FontWeights::SemiBold());
        dateText.Foreground(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(240, 235, 228, 215)));
        dateText.HorizontalAlignment(wux::HorizontalAlignment::Center);

        dateCapsule.Child(dateText);
        verticalLayout.Children().Append(dateCapsule);
        g_dateTextBlock = dateText;
    }

    rootContainer.Children().Append(verticalLayout);
    UpdateTimeAndDate();
    StartClockTimer();

    return rootContainer;
}

// Build Single Cyberpunk Neon Card Element
wuxc::Grid CreateCyberpunkFlipCard(double width, double height, double cornerRadius, wuxc::TextBlock& outText, const wchar_t* textName) {
    wuxc::Grid card;
    card.Width(width);
    card.Height(height);

    // 1. Dark Obsidian Glass Body with Electric Cyan Neon Glow Border
    wuxc::Border cyberBackplate;
    cyberBackplate.Background(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(215, 9, 12, 24)));
    cyberBackplate.BorderBrush(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(195, 0, 240, 255))); // Electric Neon Cyan
    cyberBackplate.BorderThickness(wux::Thickness{ 1.8, 1.8, 1.8, 1.8 });
    cyberBackplate.CornerRadius(wux::CornerRadiusHelper::FromUniformRadius(cornerRadius));

    // 2. Inner Neon Specular Highlight (Top sheen)
    wuxc::Border innerGlow;
    innerGlow.Background(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(24, 0, 240, 255)));
    innerGlow.CornerRadius(wux::CornerRadiusHelper::FromUniformRadius(cornerRadius - 2.0));
    innerGlow.Height(height * 0.46);
    innerGlow.VerticalAlignment(wux::VerticalAlignment::Top);
    innerGlow.Margin(wux::Thickness{ 2.0, 2.0, 2.0, 0.0 });

    // 3. Cyberpunk High-Voltage Typography (Pure bright electric white-cyan)
    wuxc::TextBlock cardText;
    cardText.Name(textName);
    cardText.FontSize((double)g_settings.clockFontSize);
    cardText.FontFamily(wuxm::FontFamily(L"Segoe UI Variable Display"));
    cardText.FontWeight(winrt::Windows::UI::Text::FontWeights::Black());
    cardText.Foreground(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(255, 230, 252, 255)));
    cardText.HorizontalAlignment(wux::HorizontalAlignment::Center);
    cardText.VerticalAlignment(wux::VerticalAlignment::Center);

    // 4. Center Horizontal Neon Laser Split Seam
    wuxc::Grid laserSeam;
    laserSeam.Height(10.0);
    laserSeam.HorizontalAlignment(wux::HorizontalAlignment::Stretch);
    laserSeam.VerticalAlignment(wux::VerticalAlignment::Center);

    // Soft laser aura (cyan glow)
    wuxs::Rectangle laserAura;
    laserAura.Height(4.0);
    laserAura.HorizontalAlignment(wux::HorizontalAlignment::Stretch);
    laserAura.Fill(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(70, 0, 240, 255)));
    laserAura.VerticalAlignment(wux::VerticalAlignment::Center);
    laserAura.Margin(wux::Thickness{ 2.0, 0.0, 2.0, 0.0 });

    // Sharp core laser line (vibrant bright cyan)
    wuxs::Rectangle laserCore;
    laserCore.Height(1.6);
    laserCore.HorizontalAlignment(wux::HorizontalAlignment::Stretch);
    laserCore.Fill(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(250, 0, 240, 255)));
    laserCore.VerticalAlignment(wux::VerticalAlignment::Center);
    laserCore.Margin(wux::Thickness{ 2.0, 0.0, 2.0, 0.0 });

    // Left and Right Cyber Edge Accents (Hot Magenta laser nodes)
    wuxs::Rectangle leftNode;
    leftNode.Width(5.0);
    leftNode.Height(10.0);
    leftNode.RadiusX(1.0);
    leftNode.RadiusY(1.0);
    leftNode.HorizontalAlignment(wux::HorizontalAlignment::Left);
    leftNode.VerticalAlignment(wux::VerticalAlignment::Center);
    leftNode.Fill(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(255, 255, 0, 128))); // Hot Magenta

    wuxs::Rectangle rightNode;
    rightNode.Width(5.0);
    rightNode.Height(10.0);
    rightNode.RadiusX(1.0);
    rightNode.RadiusY(1.0);
    rightNode.HorizontalAlignment(wux::HorizontalAlignment::Right);
    rightNode.VerticalAlignment(wux::VerticalAlignment::Center);
    rightNode.Fill(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(255, 255, 0, 128))); // Hot Magenta

    laserSeam.Children().Append(laserAura);
    laserSeam.Children().Append(laserCore);
    laserSeam.Children().Append(leftNode);
    laserSeam.Children().Append(rightNode);

    card.Children().Append(cyberBackplate);
    card.Children().Append(innerGlow);
    card.Children().Append(cardText);
    card.Children().Append(laserSeam);
    outText = cardText;

    return card;
}

// Build Cyberpunk Neon Glow Clock UI Element
wux::UIElement BuildCyberpunkClockElement() {
    wuxc::Grid rootContainer;
    rootContainer.Name(L"WindhawkCyberpunkClockContainer");
    ApplyAlignmentAndMargin(rootContainer);

    wuxc::StackPanel verticalLayout;
    verticalLayout.Orientation(wuxc::Orientation::Vertical);
    verticalLayout.HorizontalAlignment(wux::HorizontalAlignment::Center);

    wuxc::StackPanel cardsLayout;
    cardsLayout.Orientation(wuxc::Orientation::Horizontal);
    cardsLayout.HorizontalAlignment(wux::HorizontalAlignment::Center);
    cardsLayout.Spacing(g_settings.showSeconds ? 14.0 : 18.0);

    double cardWidth = g_settings.showSeconds ? (g_settings.clockFontSize * 1.45) : (g_settings.clockFontSize * 1.65);
    double cardHeight = g_settings.clockFontSize * 1.95;
    double cornerRad = 14.0;

    // 1. Hour Card
    auto hourCard = CreateCyberpunkFlipCard(cardWidth, cardHeight, cornerRad, g_hourTextBlock, L"WindhawkCyberHourText");
    cardsLayout.Children().Append(hourCard);

    // 2. Minute Card
    auto minCard = CreateCyberpunkFlipCard(cardWidth, cardHeight, cornerRad, g_minTextBlock, L"WindhawkCyberMinText");
    cardsLayout.Children().Append(minCard);

    // 3. Seconds Card (If enabled)
    if (g_settings.showSeconds) {
        auto secCard = CreateCyberpunkFlipCard(cardWidth, cardHeight, cornerRad, g_secTextBlock, L"WindhawkCyberSecText");
        cardsLayout.Children().Append(secCard);
    }

    verticalLayout.Children().Append(cardsLayout);

    // Cyberpunk HUD Date Capsule (Hot Magenta Neon Accent)
    if (g_settings.showDateCapsule) {
        wuxc::Border hudCapsule;
        hudCapsule.Background(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(200, 14, 10, 24)));
        hudCapsule.BorderBrush(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(190, 255, 0, 128))); // Hot Magenta
        hudCapsule.BorderThickness(wux::Thickness{ 1.4, 1.4, 1.4, 1.4 });
        hudCapsule.CornerRadius(wux::CornerRadiusHelper::FromUniformRadius(10.0));
        hudCapsule.Padding(wux::Thickness{ 24.0, 7.0, 24.0, 7.0 });
        hudCapsule.Margin(wux::Thickness{ 0.0, 18.0, 0.0, 0.0 });
        hudCapsule.HorizontalAlignment(wux::HorizontalAlignment::Center);

        wuxc::TextBlock dateText;
        dateText.Name(L"WindhawkCyberDateText");
        dateText.FontSize(18.0);
        dateText.FontFamily(wuxm::FontFamily(L"Segoe UI Variable Text"));
        dateText.FontWeight(winrt::Windows::UI::Text::FontWeights::SemiBold());
        dateText.Foreground(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(255, 255, 110, 185))); // Electric Pink
        dateText.HorizontalAlignment(wux::HorizontalAlignment::Center);

        hudCapsule.Child(dateText);
        verticalLayout.Children().Append(hudCapsule);
        g_dateTextBlock = dateText;
    }

    rootContainer.Children().Append(verticalLayout);
    UpdateTimeAndDate();
    StartClockTimer();

    return rootContainer;
}

// Build Pixel Digit Grid Helper (7 cols x 9 rows, 63 dots)
wuxc::Grid CreatePixelDigitGrid(PixelDigitGrid& digitRef, double dotSize, double spacing) {
    wuxc::Grid grid;
    for (int c = 0; c < 7; c++) {
        wuxc::ColumnDefinition colDef;
        colDef.Width(wux::GridLengthHelper::FromPixels(dotSize + spacing));
        grid.ColumnDefinitions().Append(colDef);
    }
    for (int r = 0; r < 9; r++) {
        wuxc::RowDefinition rowDef;
        rowDef.Height(wux::GridLengthHelper::FromPixels(dotSize + spacing));
        grid.RowDefinitions().Append(rowDef);
    }

    digitRef.dots.clear();
    digitRef.dots.reserve(63);

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 7; c++) {
            wuxs::Ellipse dot;
            dot.Width(dotSize);
            dot.Height(dotSize);
            dot.Fill(g_brushInactiveDot);
            dot.HorizontalAlignment(wux::HorizontalAlignment::Center);
            dot.VerticalAlignment(wux::VerticalAlignment::Center);
            wuxc::Grid::SetRow(dot, r);
            wuxc::Grid::SetColumn(dot, c);
            grid.Children().Append(dot);
            digitRef.dots.push_back(dot);
        }
    }
    return grid;
}

// Build Pixel Colon Helper (2 cols x 9 rows, 2x2 active dots for each colon point)
wuxc::Grid CreatePixelColon(double dotSize, double spacing) {
    wuxc::Grid grid;
    for (int c = 0; c < 2; c++) {
        wuxc::ColumnDefinition colDef;
        colDef.Width(wux::GridLengthHelper::FromPixels(dotSize + spacing));
        grid.ColumnDefinitions().Append(colDef);
    }
    for (int r = 0; r < 9; r++) {
        wuxc::RowDefinition rowDef;
        rowDef.Height(wux::GridLengthHelper::FromPixels(dotSize + spacing));
        grid.RowDefinitions().Append(rowDef);
    }

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 2; c++) {
            wuxs::Ellipse dot;
            dot.Width(dotSize);
            dot.Height(dotSize);
            bool isColonDot = (r == 2 || r == 3 || r == 5 || r == 6);
            dot.Fill(isColonDot ? g_brushActiveDot : g_brushInactiveDot);
            dot.HorizontalAlignment(wux::HorizontalAlignment::Center);
            dot.VerticalAlignment(wux::VerticalAlignment::Center);
            wuxc::Grid::SetRow(dot, r);
            wuxc::Grid::SetColumn(dot, c);
            grid.Children().Append(dot);
        }
    }
    return grid;
}

// Build Retro Pixel / LED Dot Matrix Clock Element
wux::UIElement BuildPixelClockElement() {
    wuxc::Grid rootContainer;
    rootContainer.Name(L"WindhawkPixelClockContainer");
    ApplyAlignmentAndMargin(rootContainer);

    // High-contrast brushes: 100% active white, subtle 6% ambient inactive dots
    g_brushActiveDot = wuxm::SolidColorBrush(wu::Colors::White());
    g_brushInactiveDot = wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(15, 255, 255, 255));

    // Dark frosted acrylic backplate for perfect contrast on any wallpaper
    wuxc::Border darkBackplate;
    darkBackplate.Background(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(32, 10, 14, 22)));
    darkBackplate.BorderBrush(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(15, 255, 255, 255)));
    darkBackplate.BorderThickness(wux::Thickness{ 1.0, 1.0, 1.0, 1.0 });
    darkBackplate.CornerRadius(wux::CornerRadiusHelper::FromUniformRadius(20.0));
    darkBackplate.Padding(wux::Thickness{ 26.0, 22.0, 26.0, 22.0 });
    darkBackplate.HorizontalAlignment(wux::HorizontalAlignment::Center);

    wuxc::StackPanel verticalLayout;
    verticalLayout.Orientation(wuxc::Orientation::Vertical);
    verticalLayout.HorizontalAlignment(wux::HorizontalAlignment::Center);

    wuxc::StackPanel matrixLayout;
    matrixLayout.Orientation(wuxc::Orientation::Horizontal);
    matrixLayout.HorizontalAlignment(wux::HorizontalAlignment::Center);
    matrixLayout.VerticalAlignment(wux::VerticalAlignment::Center);

    // Scale dot size appropriately for 7x9 double-pixel thickness
    double dotSize = (double)g_settings.clockFontSize * 0.095;
    double spacing = dotSize * 0.35;
    double digitGap = dotSize * 1.3;
    double colonGap = dotSize * 1.0;

    // H1 & H2
    auto h1 = CreatePixelDigitGrid(g_pixelDigits[0], dotSize, spacing);
    auto h2 = CreatePixelDigitGrid(g_pixelDigits[1], dotSize, spacing);
    h1.Margin(wux::Thickness{ 0.0, 0.0, digitGap, 0.0 });
    h2.Margin(wux::Thickness{ 0.0, 0.0, colonGap, 0.0 });
    matrixLayout.Children().Append(h1);
    matrixLayout.Children().Append(h2);

    // Colon 1 (between hours and minutes)
    auto colon1 = CreatePixelColon(dotSize, spacing);
    colon1.Margin(wux::Thickness{ 0.0, 0.0, colonGap, 0.0 });
    matrixLayout.Children().Append(colon1);

    // M1 & M2
    auto m1 = CreatePixelDigitGrid(g_pixelDigits[2], dotSize, spacing);
    auto m2 = CreatePixelDigitGrid(g_pixelDigits[3], dotSize, spacing);
    m1.Margin(wux::Thickness{ 0.0, 0.0, digitGap, 0.0 });
    matrixLayout.Children().Append(m1);
    matrixLayout.Children().Append(m2);

    // Optional Seconds (HH:MM:SS format at the same scale and alignment)
    if (g_settings.showSeconds) {
        m2.Margin(wux::Thickness{ 0.0, 0.0, colonGap, 0.0 });

        // Colon 2 (between minutes and seconds)
        auto colon2 = CreatePixelColon(dotSize, spacing);
        colon2.Margin(wux::Thickness{ 0.0, 0.0, colonGap, 0.0 });
        matrixLayout.Children().Append(colon2);

        // S1 & S2
        auto s1 = CreatePixelDigitGrid(g_pixelDigits[4], dotSize, spacing);
        auto s2 = CreatePixelDigitGrid(g_pixelDigits[5], dotSize, spacing);
        s1.Margin(wux::Thickness{ 0.0, 0.0, digitGap, 0.0 });
        matrixLayout.Children().Append(s1);
        matrixLayout.Children().Append(s2);
    }

    verticalLayout.Children().Append(matrixLayout);

    // Date display
    if (g_settings.showDateCapsule) {
        wuxc::TextBlock dateText;
        dateText.Name(L"WindhawkPixelDateText");
        dateText.FontSize(19.0);
        dateText.FontFamily(wuxm::FontFamily(L"Segoe UI Variable Text"));
        dateText.FontWeight(winrt::Windows::UI::Text::FontWeights::SemiBold());
        dateText.Foreground(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(235, 255, 255, 255)));
        dateText.HorizontalAlignment(wux::HorizontalAlignment::Center);
        dateText.Margin(wux::Thickness{ 0.0, 18.0, 0.0, 0.0 });

        verticalLayout.Children().Append(dateText);
        g_dateTextBlock = dateText;
    }

    darkBackplate.Child(verticalLayout);
    rootContainer.Children().Append(darkBackplate);

    UpdateTimeAndDate();
    StartClockTimer();

    return rootContainer;
}

// Build Minimalist Digital Clock Element
wux::UIElement BuildMinimalClockElement() {
    wuxc::Grid rootContainer;
    rootContainer.Name(L"WindhawkMinimalClockContainer");
    ApplyAlignmentAndMargin(rootContainer);

    wuxc::StackPanel verticalLayout;
    verticalLayout.Orientation(wuxc::Orientation::Vertical);
    verticalLayout.HorizontalAlignment(wux::HorizontalAlignment::Center);

    wuxc::TextBlock timeText;
    timeText.FontSize((double)(g_settings.clockFontSize * 1.3));
    timeText.FontFamily(wuxm::FontFamily(L"Segoe UI Variable Display"));
    timeText.FontWeight(winrt::Windows::UI::Text::FontWeights::SemiLight());
    timeText.Foreground(wuxm::SolidColorBrush(wu::Colors::White()));
    timeText.HorizontalAlignment(wux::HorizontalAlignment::Center);

    verticalLayout.Children().Append(timeText);
    g_minimalTimeTextBlock = timeText;

    if (g_settings.showDateCapsule) {
        wuxc::TextBlock dateText;
        dateText.FontSize(20.0);
        dateText.FontFamily(wuxm::FontFamily(L"Segoe UI Variable Text"));
        dateText.FontWeight(winrt::Windows::UI::Text::FontWeights::Normal());
        dateText.Foreground(wuxm::SolidColorBrush(wu::ColorHelper::FromArgb(210, 255, 255, 255)));
        dateText.HorizontalAlignment(wux::HorizontalAlignment::Center);
        dateText.Margin(wux::Thickness{ 0.0, 10.0, 0.0, 0.0 });
        verticalLayout.Children().Append(dateText);
        g_dateTextBlock = dateText;
    }

    rootContainer.Children().Append(verticalLayout);
    UpdateTimeAndDate();
    StartClockTimer();

    return rootContainer;
}

// Factory function for selected clock style
wux::UIElement BuildClockElement() {
    if (g_settings.clockStyle == L"pixel") {
        return BuildPixelClockElement();
    } else if (g_settings.clockStyle == L"vintage") {
        return BuildVintageClockElement();
    } else if (g_settings.clockStyle == L"cyberpunk") {
        return BuildCyberpunkClockElement();
    } else if (g_settings.clockStyle == L"minimal") {
        return BuildMinimalClockElement();
    }
    return BuildFlipClockElement();
}

// Thread-safe dynamic UI rebuild on settings change
void RebuildClockUI() {
    if (!g_lockRootGrid) return;
    auto dispatcher = g_lockRootGrid.Dispatcher();
    if (!dispatcher) return;

    dispatcher.RunAsync(winrt::Windows::UI::Core::CoreDispatcherPriority::Normal, []() {
        if (!g_lockRootGrid) return;

        if (g_activeClockElement) {
            uint32_t index = 0;
            if (g_lockRootGrid.Children().IndexOf(g_activeClockElement, index)) {
                g_lockRootGrid.Children().RemoveAt(index);
            }
            g_activeClockElement = nullptr;
        }

        g_hourTextBlock = nullptr;
        g_minTextBlock = nullptr;
        g_secTextBlock = nullptr;
        g_minimalTimeTextBlock = nullptr;
        g_dateTextBlock = nullptr;
        for (int i = 0; i < 6; i++) {
            g_pixelDigits[i].dots.clear();
        }

        if (g_settings.clockStyle != L"defaultOnly") {
            g_activeClockElement = BuildClockElement();
            g_lockRootGrid.Children().Append(g_activeClockElement);
            Wh_Log(L"Clock UI successfully rebuilt for style: %s (showSec=%d)",
                   g_settings.clockStyle.c_str(), g_settings.showSeconds);
        }
    });
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
                    if ((name == L"LockRootGrid" || name == L"MainPageContainer") && !g_clockInjected)
                    {
                        auto grid = frameworkElement.try_as<wuxc::Grid>();
                        if (grid)
                        {
                            g_lockRootGrid = grid;
                            Wh_Log(L"Found lock screen root grid: %s. Injecting Clock...", name.c_str());
                            if (g_settings.clockStyle != L"defaultOnly")
                            {
                                g_activeClockElement = BuildClockElement();
                                grid.Children().Append(g_activeClockElement);
                                g_clockInjected = true;
                                Wh_Log(L"Clock successfully injected! Style: %s", g_settings.clockStyle.c_str());
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
    g_clockInjected = false;
    g_activeClockElement = nullptr;
    g_lockRootGrid = nullptr;
}

void Wh_ModSettingsChanged() {
    Wh_Log(L"Mod settings changed (Wh_ModSettingsChanged)...");
    LoadSettings();
    RebuildClockUI();
}
