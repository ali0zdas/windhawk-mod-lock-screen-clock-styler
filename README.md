<div align="center">

# 🔒 Windows 11 Lock Screen Styler

**Elevate your Windows 11 lock screen with modern bespoke clock aesthetics, frosted acrylic cards, live power telemetry, and clean clutter-free layout controls.**

[![Windhawk Mod](https://img.shields.io/badge/Windhawk-Mod-00A4EF?style=for-the-badge&logo=windows11&logoColor=white)](https://windhawk.net/)
[![Windows 11](https://img.shields.io/badge/Windows_11-24H2_%7C_25H2_%7C_26H2-0078D4?style=for-the-badge&logo=windows&logoColor=white)](https://www.microsoft.com/windows)
[![C++20 / C++/WinRT](https://img.shields.io/badge/C%2B%2B-20_%2F_WinRT-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://docs.microsoft.com/en-us/windows/uwp/cpp-and-winrt-apis/)
[![Version](https://img.shields.io/badge/Version-0.3.1-success?style=for-the-badge)](https://github.com/ali0zdas/WindhawkMod-Windows-Lock-Screen-Styler/releases)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](LICENSE)

<br/>

**[ EN English ](README.md)** &nbsp;&bull;&nbsp; **[ 🇹🇷 Türkçe ](README-TÜRKÇE.md)**

---

</div>

## 🌟 Overview

**Windows 11 Lock Screen Styler** is a high-performance native [Windhawk](https://windhawk.net/) customization mod for the Windows 11 lock screen application (`LockApp.exe`).

It replaces the default Windows lock screen clock and MSN news/widget clutter with six distinct clock aesthetics — ranging from Apple macOS Sonoma typography and physical split-flap mechanical flip cards to authentic 7x11 retro LED dot matrices and tactical Cyberpunk HUD terminals. Built from the ground up using **C++/WinRT** and the Windows UI XAML visual tree diagnostics API, it integrates directly into the compositor with zero background battery drain and full thread safety.

> [!NOTE]
> **Safety First:** This mod exclusively modifies the user-space lock app (`LockApp.exe`). It does **not** inject into or hook `LogonUI.exe` or `winlogon.exe` (Secure Desktop), ensuring system stability and zero security risks.

---

## 🎨 Themes & Clock Styles

| Style | Key | Aesthetic Description | Default Placement |
| :--- | :---: | :--- | :---: |
| 👾 **Retro Pixel / LED Matrix** | `pixel` | Authentic 7x11 double-pixel LED dot matrix display with subtle ambient dot glow and frosted acrylic contrast backplate. | Center |
| ⏳ **Modern Flip Clock** | `flip` | Split acrylic frosted glass cards with bold proportions, Fliqlo-inspired horizontal scissors-cut split seam, and smooth rounded corners. | Center |
| 📜 **Classic Flip Clock** | `vintage` | Solari-inspired mechanical train terminal clock with matte charcoal flap cards, aged ivory typography, split seam, and axle hinge clips. | Center |
| 🪐 **Minimalist Sonoma** | `macos` | Apple lock screen aesthetic with date positioned above the time, ultra-slender display numerals, dual-layer atmospheric shadows, and elegant left alignment. | Bottom-Left |
| ⚡ **Cyberpunk Sci-Fi HUD** | `cyberpunk` | Tactical Netrunner HUD terminal with obsidian chassis, acid yellow & hot magenta corner brackets, top telemetry diagnostic bar, and pulsating laser dividers (`//`). | Center |
| 🌌 **Minimalist Aura** | `aura` | Clean frameless floating typography with ambient soft drop-shadow depth and an elegant frosted date capsule. | Center |
| 🪟 **Default Clock Only** | `defaultOnly` | Keeps the stock Windows 11 lock screen clock while giving you one-click suppression of MSN news, stocks, and weather cards. | Stock |

---

## ✨ Core Highlights & Features

- 🔋 **Live Smart Battery Telemetry Capsule:**
  - Displays real-time laptop battery percentage with charging indicators (`⚡` charging, `🔋` battery level).
  - Automatically hidden on desktop PCs without cluttering the screen.
- 🕒 **12-Hour & 24-Hour Time Engine:**
  - Full support for standard 24-hour time or 12-hour AM/PM format.
  - Bespoke, theme-tailored AM/PM status badges (vintage flip stamp, tactical HUD status pill, minimal text).
- ⏱️ **Real-Time Seconds Toggle with Memory:**
  - Opt-in live seconds display (supported on Cyberpunk, Retro Pixel, and Minimalist styles; automatically disabled on physical flip clocks).
  - Remembers user preferences per theme independently without cross-theme interference.
- 🛡️ **Single-Instance Guard & Reconnect Engine:**
  - Automatically watches for Windows LockApp visual tree re-creation.
  - Dynamically cleans up stale references and re-injects the clock safely, preventing duplicate clock glitches.
- 🧵 **Thread-Safe Reactive UI:**
  - All setting updates, UI rebuilds, and uninitialization cleanups are strictly dispatched to the XAML UI thread via `CoreDispatcher.RunAsync`, eliminating data races and crashes.
- 🧹 **Stock Widget & Clutter Cleaner:**
  - Instantly hide MSN weather, sports scores, finance stocks, and news cards with a single toggle.
- 📐 **Smart Theme-Aware Alignment:**
  - Automatic (`auto`) alignment aligns Minimalist Sonoma to the bottom-left corner while keeping other clock styles centered, with full manual override (`center`, `bottomLeft`, `left`, `right`).

---

## ⚙️ Configuration Reference

All settings can be customized instantly from the **Settings** tab in the Windhawk user interface:

| Option | Setting Key | Allowed Values / Range | Default | Purpose |
| :--- | :--- | :--- | :---: | :--- |
| **Clock Style** | `clockStyle` | `pixel`, `flip`, `vintage`, `macos`, `cyberpunk`, `aura`, `defaultOnly` | `pixel` | Selects visual clock theme. |
| **Time Format** | `timeFormat` | `24h`, `12h` | `24h` | Toggle between 24-hour and 12-hour AM/PM display. |
| **Clock Alignment** | `clockAlignment` | `auto`, `center`, `bottomLeft`, `left`, `right` | `auto` | Screen placement (`auto` uses theme default). |
| **Show Seconds** | `showSeconds` | `true`, `false` | `false` | Real-time seconds counter (theme-aware). |
| **Battery Status** | `showBatteryStatus`| `true`, `false` | `false` | Laptop battery percentage and charging capsule. |
| **Show Date Capsule** | `showDateCapsule` | `true`, `false` | `true` | Localized date and weekday display capsule. |
| **Glass Opacity** | `glassOpacity` | `0` to `255` | `45` | Translucency alpha value for frosted cards. |
| **Digit Font Size** | `clockFontSize` | `40` to `160` | `92` | Base font size for clock digits. |
| **Vertical Offset** | `verticalOffset` | `-200` to `+400` px | `0` | Vertical screen shift adjustment. |
| **Hide Default Widgets**| `hideDefaultWidgets`| `true`, `false` | `true` | Hides MSN weather, news, and stock widgets. |
| **Hide Default Clock** | `hideDefaultClock` | `true`, `false` | `true` | Replaces the stock Windows 11 lock screen clock. |

---

## 🚀 Installation & Usage

1. Download and install **[Windhawk](https://windhawk.net/)** (if not already installed).
2. Open the Windhawk manager, navigate to the **Advanced** tab, and click **Create Mod**.
3. Copy the entire source code from [`windows-11-lock-screen-styler.wh.cpp`](./windows-11-lock-screen-styler.wh.cpp) and paste it into the Windhawk editor.
4. Click **Compile** (`Ctrl + B`).
5. Once compiled, save and enable the mod.
6. Press <kbd>Win</kbd> + <kbd>L</kbd> to lock your screen and enjoy your new lock screen clock!

> [!TIP]
> You can tweak themes, font sizes, and alignments on the fly in the **Settings** tab inside Windhawk without needing to recompile.

---

## 🔒 Security & Architecture

- **Target Process:** Injects strictly into `LockApp.exe` using standard Windows Diagnostics TAP (`InitializeXamlDiagnosticsEx`).
- **No Secure Desktop Access:** Never hooks into or touches `LogonUI.exe` or `winlogon.exe`. Credential entry and authentication remain 100% untouched and secure.
- **Resource Efficient:** Utilizes dirty-checking caches and disables timers when the screen is unlocked or when running default clock mode, ensuring virtually zero CPU and battery impact.
- **Compatibility:** Tested and validated on Windows 11 versions **23H2**, **24H2**, and **25H2** (Build 26200+).

---

## 📄 License

This project is licensed under the [MIT License](LICENSE) &copy; 2026 [ali0zdas](https://github.com/ali0zdas).
