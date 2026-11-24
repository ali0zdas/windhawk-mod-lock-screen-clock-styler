<div align="center">

# Lock Screen Clock Styler

**Elevate your Windows 11 lock screen clock with modern bespoke aesthetics, frosted acrylic cards, live power telemetry, and clean clutter-free layout controls.**

[![Windhawk Mod](https://img.shields.io/badge/Get_it_on-Windhawk-00A4EF?style=for-the-badge&logo=windows11&logoColor=white)](https://windhawk.net/mods/lock-screen-clock-styler)
[![Windows 11](https://img.shields.io/badge/Windows_11-24H2_%7C_25H2_%7C_26H2-0078D4?style=for-the-badge&logo=windows&logoColor=white)](https://www.microsoft.com/windows)
[![C++20 / C++/WinRT](https://img.shields.io/badge/C%2B%2B-20_%2F_WinRT-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://docs.microsoft.com/en-us/windows/uwp/cpp-and-winrt-apis/)
[![Version](https://img.shields.io/badge/Version-3.0.0-success?style=for-the-badge)](https://github.com/ali0zdas/windhawk-mod-lock-screen-clock-styler/releases)
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg?style=for-the-badge)](LICENSE)

<a href="https://windhawk.net/mods/lock-screen-clock-styler"><img src="https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fmods.windhawk.net%2Fcatalog.json&query=%24.mods%5B%27lock-screen-clock-styler%27%5D.details.users&label=Active%20Users%20on%20Windhawk&color=6366f1&labelColor=0f172a&logo=windows11&logoColor=38bdf8&style=for-the-badge" height="34" alt="Active Users on Windhawk" /></a>
<a href="https://windhawk.net/mods/lock-screen-clock-styler"><img src="https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fmods.windhawk.net%2Fcatalog.json&query=%24.mods%5B%27lock-screen-clock-styler%27%5D.details.rating&label=%E2%98%85%20Rating&suffix=%2F10&color=eab308&labelColor=0f172a&style=for-the-badge" height="34" alt="Community Rating" /></a>

---

</div>

##  Overview

**Lock Screen Clock Styler** is a high-performance native [Windhawk](https://windhawk.net/) customization mod for the Windows 11 lock screen application (`LockApp.exe`).

It replaces the default Windows lock screen clock with 9 distinct clock aesthetics — ranging from macOS Sonoma typography and physical split-flap mechanical flip cards to authentic retro LED dot matrices, vertical stack layouts, and tactical Cyberpunk HUD terminals. Built with **C++/WinRT**, it discovers the lock screen visual tree from the lock screen's own UI thread and injects custom XAML directly into the compositor with no XAML DispatcherTimer and full thread safety.

> [!NOTE]
> **Safety First:** This mod exclusively modifies the user-space lock app (`LockApp.exe`). It does **not** inject into or hook `LogonUI.exe` or `winlogon.exe` (Secure Desktop), ensuring system stability and zero security risks.

---

## 📸 Screenshots

<p align="center">
  <img src="https://raw.githubusercontent.com/ali0zdas/windhawk-mod-lock-screen-clock-styler/main/screenshots/Retro%20Pixel.png" width="49%" alt="Retro Pixel / LED Matrix" />
  <img src="https://raw.githubusercontent.com/ali0zdas/windhawk-mod-lock-screen-clock-styler/main/screenshots/vertical%20pixel.png" width="49%" alt="Vertical Pixel / Nothing OS (Bahnschrift)" />
  <br />
  <img src="https://raw.githubusercontent.com/ali0zdas/windhawk-mod-lock-screen-clock-styler/main/screenshots/vertical%20modern.png" width="49%" alt="Vertical Modern / Dual Weight (Segoe UI)" />
  <img src="https://raw.githubusercontent.com/ali0zdas/windhawk-mod-lock-screen-clock-styler/main/screenshots/vertical%20poster.png" width="49%" alt="Vertical Poster / Heavy Impact (Impact)" />
  <br />
  <img src="https://raw.githubusercontent.com/ali0zdas/windhawk-mod-lock-screen-clock-styler/main/screenshots/modern%20flip%20clock.png" width="49%" alt="Modern Flip Clock" />
  <img src="https://raw.githubusercontent.com/ali0zdas/windhawk-mod-lock-screen-clock-styler/main/screenshots/classical%20flip%20clock.png" width="49%" alt="Classic Flip Clock" />
  <br />
  <img src="https://raw.githubusercontent.com/ali0zdas/windhawk-mod-lock-screen-clock-styler/main/screenshots/sonoma.png" width="49%" alt="Minimalist Sonoma" />
  <img src="https://raw.githubusercontent.com/ali0zdas/windhawk-mod-lock-screen-clock-styler/main/screenshots/cyberpunk%20style.png" width="49%" alt="Cyberpunk Sci-Fi HUD" />
</p>

> Captured on Windows 11 (26H2).

---

## 🎨 Themes & Clock Styles

| Style | Key | Aesthetic Description |
| :--- | :---: | :--- |
| 👾 **Retro Pixel / LED Matrix** | `pixel` | Authentic 7x11 double-pixel LED dot matrix display with subtle ambient dot glow and frosted acrylic contrast backplate. |
| 📱 **Vertical Pixel / Nothing OS (Bahnschrift)** | `verticalBahnschrift` | Nothing OS and DIN-standard geometric typography in a 2-row vertical stack, featuring SemiBold Bahnschrift numerals with subtle minute contrast and compact line spacing. |
| ✨ **Vertical Modern / Dual Weight (Segoe UI)** | `verticalSegoe` | Striking dual-weight vertical presentation pairing bold hour digits with extra-light Segoe UI Variable Display minutes for high typographic hierarchy and ultra-clean modern framing. |
| 📰 **Vertical Poster / Heavy Impact (Impact)** | `verticalImpact` | Bold condensed Swiss poster aesthetic utilizing ultra-heavy Impact typography, tight vertical spacing, and high-impact visual presence reminiscent of brutalist editorial layouts. |
| 🟩 **ANSI Shadow (Terminal ASCII)** | `ansiShadow` | Retro terminal ASCII block-art clock rendered with crisp monospace phosphor palettes (Green, Amber, Cyan, Monochrome). |
| ⏳ **Modern Flip Clock** | `flip` | Split acrylic frosted glass cards with bold proportions, Fliqlo-inspired horizontal scissors-cut split seam, and smooth rounded corners. |
| 📜 **Classic Flip Clock** | `vintage` | Solari-inspired mechanical train terminal clock with matte charcoal flap cards, aged ivory typography, split seam, and axle hinge clips. |
| 🪐 **Minimalist Sonoma** | `macos` | Apple lock screen aesthetic with date positioned above the time, ultra-slender display numerals, dual-layer atmospheric shadows, and elegant left alignment. |
| ⚡ **Cyberpunk Sci-Fi HUD** | `cyberpunk` | Tactical Netrunner HUD terminal with obsidian chassis, acid yellow & hot magenta corner brackets, top telemetry diagnostic bar, and pulsating laser dividers (`//`). |
| 🪟 **Default Clock Only** | `defaultOnly` | Keeps the stock Windows 11 lock screen clock. Widget suppression remains available through its own toggle. |

---

## ✨ Core Highlights & Features

- 🔋 **Live Smart Battery Telemetry Capsule:**
  - Displays real-time laptop battery percentage with charging indicators (`⚡` charging, `🔋` battery level).
  - Automatically hidden on desktop PCs without cluttering the screen.
- 🕒 **12-Hour & 24-Hour Time Engine:**
  - Full support for standard 24-hour time or 12-hour AM/PM format.
  - Bespoke, theme-tailored AM/PM status badges (vintage flip stamp, tactical HUD status pill, minimal text).
- ⏱️ **Real-Time Seconds Toggle:**
  - Opt-in live seconds display, supported by every style except the mechanical flip clocks and 2-row vertical stack styles.
  - The settings toggle is the single source of truth, so switching styles never leaves a stale per-theme preference behind.
- 🛡️ **Single-Instance Guard & Reconnect Engine:**
  - Periodically rescans the lock screen visual tree and re-injects the clock safely when Windows rebuilds it.
  - Removes the previous clock before attaching the new one, preventing duplicate clock glitches.
- 🧵 **Thread-Safe UI Dispatch:**
  - A `WH_GETMESSAGE` hook on the lock screen UI thread drives updates; every XAML read and write stays on that thread.
  - Settings reloads and unload cleanup are dispatched synchronously with a `WH_CALLWNDPROC` message, so no mod code can be left running when the DLL unloads.
- 🧩 **No XAML Diagnostics TAP:**
  - Finds the lock screen tree through `Window::Current().Content()` and `VisualTreeHelper` instead of registering a XAML Diagnostics TAP.
  - Can run alongside other XAML-based Windhawk mods such as Windows 11 Start Menu Styler.
- 🧹 **Stock Widget & Clutter Cleaner:**
  - Instantly hide MSN weather, sports scores, finance stocks, and news cards with a single toggle.
- 📐 **Smart Theme-Aware Alignment:**
  - Automatic (`auto`) alignment aligns Minimalist Sonoma to the bottom-left corner while keeping other clock styles centered, with full manual override (`center`, `bottomLeft`, `left`, `right`).

---

## 🆕 What's New in v3.0.0

- 🟩 **New ANSI Shadow (Terminal ASCII) Clock Style:** Added a retro terminal ASCII block-art clock with terminal color themes (Matrix Green, Amber CRT, Cyber Cyan, Classic Monochrome).
- 🎨 **Per-Theme Customization Groups (100% Backward Compatible):** Added dedicated settings sections for **Retro Pixel**, **Vertical Stack Clocks**, **ANSI Shadow**, **Flip Clocks**, **Minimalist Sonoma**, and **Cyberpunk Sci-Fi HUD** while keeping all existing top-level keys untouched:
  - **14 Curated Color Options** with unique color emojis (`Pure White`, `Black`, `Soft Silver`, `Red`, `Orange`, `Yellow`, `Electric Cyan`, `Sky Blue`, `Matrix Green`, `Warm Amber`, `Coral Red`, `Neon Magenta`, `Soft Violet`, `Theme Default`).
  - **Built-In Font Selector & Shadow Toggle:** Choose from 8 built-in Windows fonts and toggle drop shadows on Vertical Stack and Minimalist Sonoma clocks.
  - **Retro Pixel & Flip Controls:** Customize LED dot shape (`Circle`, `Square`, `Rounded`), frosted backplate toggle & opacity (`0–255`), Flip card corner radius, center split seam, and Cyberpunk HUD color presets / header bar / chassis opacity.
- ✨ **Polished Settings UI:** Added emoji prefixes across all 14 locales, refined default `clockFontSize` to `165`, and removed redundant toggles.

---

## ⚙️ Configuration Reference

All settings can be customized instantly from the **Settings** tab in the Windhawk user interface:

| Option | Setting Key | Allowed Values / Range | Default | Purpose |
| :--- | :--- | :--- | :---: | :--- |
| **Clock Style** | `clockStyle` | `pixel`, `verticalBahnschrift`, `verticalSegoe`, `verticalImpact`, `ansiShadow`, `flip`, `vintage`, `macos`, `cyberpunk`, `defaultOnly` | `pixel` | Selects visual clock theme. |
| **Time Format** | `timeFormat` | `24h`, `12h` | `24h` | Toggle between 24-hour and 12-hour AM/PM display. |
| **Show Seconds** | `showSeconds` | `true`, `false` | `true` | Live seconds (all styles except `flip`, `vintage`, and vertical stack themes). |
| **Digit Font Size** | `clockFontSize` | `20` to `300` | `165` | Base font size for clock digits. |
| **Vertical Offset** | `verticalOffset` | `-200` to `+400` px | `0` | Vertical screen shift adjustment. |
| **Clock Alignment** | `clockAlignment` | `auto`, `center`, `bottomLeft`, `left`, `right` | `auto` | Screen placement (`auto` uses theme default). |
| **Show Date Display** | `showDateCapsule` | `true`, `false` | `true` | Localized date and weekday display. |
| **Hide Default Widgets**| `hideDefaultWidgets`| `true`, `false` | `false` | Hides MSN weather, news, and sports widgets. |
| **Battery Status** | `showBatteryStatus`| `true`, `false` | `false` | Laptop battery percentage and charging capsule. |
| **Per-Theme Groups** | `pixelSettings.*`, `verticalSettings.*`, `ansiSettings.*`, `flipSettings.*`, `minimalistSettings.*`, `cyberpunkSettings.*` | Theme-specific controls | Theme defaults | Colors, fonts, shadows, LED shape, backplate & card opacity, corner radius, HUD presets. |

---

## 🚀 Installation & Usage

### Method 1: Official Windhawk Repository (Recommended)

1. Download and install **[Windhawk](https://windhawk.net/)** (if not already installed).
2. Open the official mod page: **[Lock Screen Clock Styler on Windhawk](https://windhawk.net/mods/lock-screen-clock-styler)** (or search for **Lock Screen Clock Styler** inside the Windhawk **Explore** tab).
3. Click **Details** &rarr; **Install**.
4. Press <kbd>Win</kbd> + <kbd>L</kbd> to lock your screen and enjoy your new lock screen clock!

### Method 2: Manual Installation (for Developers)

1. Open the Windhawk manager, navigate to the **Advanced** tab, and click **Create Mod**.
2. Copy the entire source code from [`lock-screen-clock-styler.wh.cpp`](./lock-screen-clock-styler.wh.cpp) and paste it into the Windhawk editor.
3. Click **Compile** (`Ctrl + B`).
4. Once compiled, save and enable the mod.

> [!TIP]
> You can tweak themes, font sizes, live seconds, and alignments on the fly in the **Settings** tab inside Windhawk without needing to recompile.

---

## 🔒 Security & Architecture

- **Target Process:** Injects strictly into `LockApp.exe`, installs a message hook on its `Windows.UI.Core.CoreWindow` thread, and walks the visual tree from that UI thread. No XAML Diagnostics TAP is registered.
- **No Secure Desktop Access:** Never hooks into or touches `LogonUI.exe` or `winlogon.exe`. Credential entry and authentication remain 100% untouched and secure.
- **Resource Efficient:** Uses dirty-checking caches and message-driven updates (500 ms with seconds, 1000 ms otherwise) instead of a polling timer. Default-clock mode performs no clock rendering at all.
- **Compatibility:** Tested and validated on Windows 11 versions **24H2**, **25H2**, and **26H2** (Build 26200+). The TAP-free design allows coexistence with other XAML-based Windhawk mods.

---

## 🤝 Contributing & Feedback

Feedback, bug reports, and theme suggestions are warmly welcomed! If you have an idea for a new clock style, encounter an issue, or would like to contribute code:
- Open an issue or submit a pull request on the [GitHub repository](https://github.com/ali0zdas/windhawk-mod-lock-screen-clock-styler).
- Share your setup or suggest new aesthetic styles for upcoming releases!

---

## 📄 License

This project is licensed under the [GNU General Public License v3.0](LICENSE) &copy; 2026 [ali0zdas](https://github.com/ali0zdas).
