# Windows 11 Lock Screen Styler

A [Windhawk](https://windhawk.net/) mod that customizes the Windows 11 lock screen (`LockApp.exe`) with modern clock designs, frosted glass cards, dynamic date displays, and clutter-free layout options.

[Türkçe README](README-TÜRKÇE.md)

---

## ✨ Features

- **Minimalist Sonoma (Clean Typography):** Apple-inspired lock screen typography with date positioned elegantly above the time, slender display numerals, dual-layer atmospheric drop-shadow depth, and default bottom-left (`bottomLeft`) or center placement.
- **Modern Flip Clock:** Split frosted glass cards for hours and minutes with bold, near-square proportions and an elegant horizontal flip seam.
- **Classic Flip Clock:** Classic mechanical Solari-inspired flip clock with matte charcoal flap cards, aged ivory cream typography, mechanical split seam, and hinge axle clips.
- **Cyberpunk Sci-Fi HUD Terminal:** Bespoke Netrunner tactical HUD terminal with dark obsidian glass chassis, tactical corner brackets in acid yellow & hot magenta, top telemetry diagnostic bar, electric cyan digits with pulsating tactical slash dividers (`//`), and bottom telemetry date logger.
- **Minimalist Aura / Floating Clock:** Frameless floating typography with ambient soft drop-shadow depth and an elegant frosted date pill.
- **Retro Pixel / LED Matrix Clock:** Authentic 7x11 double-pixel dot matrix display with subtle ambient dot illumination and frosted acrylic contrast backplate.
- **Live Battery & Charging Capsule:** Smart power telemetry pill indicating live laptop battery percentage and charging state (`⚡` / `🔋`), automatically hidden on desktop systems.
- **12-Hour / 24-Hour Format:** Switch between 24-hour time and 12-hour time with dedicated AM/PM indicators across themes.
- **Seconds Display:** Optional real-time seconds toggle (direct support on Cyberpunk & Retro Pixel; separately opt-in on Minimalist styles). Automatically disabled for flip clocks.
- **Single Clock Instance Guard:** Re-attaches or moves the clock safely when Windows rebuilds the lock screen visual tree, preventing duplicate clocks.
- **Dynamic Date Capsule:** Localized weekday and date display positioned neatly under or above the clock.
- **Hide Stock Clutter:** One-click toggles to hide default MSN weather, sports, and news widgets.
- **Replace Default Clock:** Seamlessly replaces the stock Windows 11 lock screen clock.
- **Customizable Appearance:** Adjust glass opacity, font size, alignment, and vertical offsets.
- **Multi-Language Support:** Native English and Turkish (`tr-TR`) UI settings.

---

## 🛠️ How to Install

1. Install and launch [Windhawk](https://windhawk.net/).
2. Open **Advanced** -> **Create Mod** (or browse from the catalog once published).
3. Paste the contents of [`windows-11-lock-screen-styler.wh.cpp`](./windows-11-lock-screen-styler.wh.cpp).
4. Click **Compile** (`Ctrl + B`) and save the mod.
5. Lock your PC (`Win + L`) to see it in action!

---

## ⚙️ Mod Settings

| Setting | Description | Default |
| :--- | :--- | :--- |
| **Clock Style** | Choose between Retro Pixel / LED Matrix (`pixel`), Modern Flip Clock (`flip`), Classic Flip Clock (`vintage`), Minimalist Sonoma (`macos`), Cyberpunk HUD Terminal (`cyberpunk`), Minimalist Aura / Floating Clock (`aura`), or Default Clock (`defaultOnly`) | `pixel` |
| **Time Format** | Select 24-Hour (`24h`) or 12-Hour AM/PM (`12h`) format | `24h` |
| **Show Seconds** | Toggle seconds display (Cyberpunk, Retro Pixel and Minimalist styles; automatically disabled for flip clocks) | `Disabled` |
| **Show Battery Status** | Display laptop battery percentage and charging status capsule (auto-hidden on desktop PCs) | `Disabled` |
| **Glass Opacity** | Card translucency alpha value (0 - 255) | `45` |
| **Digit Font Size** | Font size for clock digits | `92` |
| **Vertical Offset** | Shift clock position up or down (-200 to +400 px) | `0` |
| **Clock Alignment** | Screen alignment (`auto`, `center`, `left`, `right`, `bottomLeft`; `auto` uses `bottomLeft` for Sonoma and `center` for other styles) | `auto` |
| **Hide Default Widgets**| Hide MSN weather, news, and finance widgets | `Enabled` |
| **Hide Default Clock** | Hide the stock Windows 11 clock and date | `Enabled` |
| **Show Date Capsule** | Display date capsule beneath cards | `Enabled` |

---

## 🔒 Security & Compatibility

- Injects only into the lock screen application (`LockApp.exe`).
- Does **not** touch `LogonUI.exe` or `winlogon.exe` (Secure Desktop).
- Compatible with Windows 11 (tested on Windows 11 23H2 / 24H2 / 25H2).

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).
