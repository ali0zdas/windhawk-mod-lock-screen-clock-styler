# Windows 11 Lock Screen Styler

A [Windhawk](https://windhawk.net/) mod that customizes the Windows 11 lock screen (`LockApp.exe`) with modern clock designs, frosted glass cards, dynamic date displays, and clutter-free layout options.

[Türkçe README](README-TÜRKÇE.md)

---

## ✨ Features

- **Modern Flip Clock:** Split frosted glass cards for hours and minutes with an elegant seam.
- **Retro Vintage Flip Clock:** Classic mechanical Solari-inspired flip clock with matte charcoal flap cards, aged ivory cream typography, mechanical split seam, and hinge axle clips.
- **Retro Pixel / LED Matrix Clock:** Authentic 7x9 double-pixel dot matrix display with subtle ambient dot illumination and frosted acrylic contrast backplate.
- **Seconds Display:** Optional real-time seconds (`HH:MM:SS`) toggle aligned with the clock.
- **Dynamic Date Capsule:** Localized weekday and date display positioned neatly under the clock.
- **Hide Stock Clutter:** One-click toggles to hide default MSN weather, sports, and news widgets.
- **Replace Default Clock:** Seamlessly replaces the stock Windows 11 lock screen clock.
- **Customizable Appearance:** Adjust glass opacity, card corner radius, font size, alignment, and vertical offsets.
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
| **Clock Style** | Choose between Frosted Glass Flip Clock (`flip`), Retro Vintage Flip Clock (`vintage`), Retro Pixel / LED Matrix (`pixel`), Minimalist Digital (`minimal`), or Default Clock (`defaultOnly`) | `flip` |
| **Show Seconds** | Toggle seconds display (`HH:MM:SS`) | `Disabled` |
| **Glass Opacity** | Card translucency alpha value (0 - 255) | `45` |
| **Card Corner Radius** | Curvature radius of the cards (px) | `22` |
| **Digit Font Size** | Font size for clock digits | `92` |
| **Vertical Offset** | Shift clock position up or down (-200 to +400 px) | `0` |
| **Clock Alignment** | Screen alignment (`center`, `left`, `right`) | `center` |
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
