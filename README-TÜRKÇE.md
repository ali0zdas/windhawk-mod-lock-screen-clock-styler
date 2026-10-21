<div align="center">

# 🔒 Windows 11 Kilit Ekranı Özelleştirici (Lock Screen Styler)

**Windows 11 kilit ekranınızı modern saat tasarımları, akrilik buzlu cam paneller, canlı pil telemetrisi ve temiz yerleşim denetimleriyle baştan yaratın.**

[![Windhawk Mod](https://img.shields.io/badge/Windhawk-Mod-00A4EF?style=for-the-badge&logo=windows11&logoColor=white)](https://windhawk.net/)
[![Windows 11](https://img.shields.io/badge/Windows_11-23H2_%7C_24H2_%7C_25H2-0078D4?style=for-the-badge&logo=windows&logoColor=white)](https://www.microsoft.com/windows)
[![C++20 / C++/WinRT](https://img.shields.io/badge/C%2B%2B-20_%2F_WinRT-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://docs.microsoft.com/en-us/windows/uwp/cpp-and-winrt-apis/)
[![Sürüm](https://img.shields.io/badge/S%C3%BCr%C3%BCm-0.3.1-success?style=for-the-badge)](https://github.com/ali0zdas/WindhawkMod-Windows-Lock-Screen-Styler/releases)
[![Lisans: MIT](https://img.shields.io/badge/Lisans-MIT-yellow.svg?style=for-the-badge)](LICENSE)

<br/>

**[ 🇬🇧 English ](README.md)** &nbsp;&bull;&nbsp; **[ 🇹🇷 Türkçe ](README-TÜRKÇE.md)**

---

</div>

## 🌟 Genel Bakış

**Windows 11 Lock Screen Styler**, Windows 11 kilit ekranı uygulamasını (`LockApp.exe`) zenginleştirmek ve özelleştirmek için geliştirilmiş yerel ve yüksek performanslı bir [Windhawk](https://windhawk.net/) modudur.

Standart Windows kilit ekranı saatini ve kalabalık MSN haber/widget kartlarını gizleyerek yerine 6 farklı özel tasarım saat estetiği getirir: Apple macOS Sonoma tipografisi, çift yapraklı Fliqlo tarzı buzlu cam flip saat, Solari mekanik tren garı saati, otantik 7x11 retro LED nokta matrisi ve taktiksel Cyberpunk HUD terminali. **C++/WinRT** mimarisi ve XAML görsel ağaç teşhis arayüzü ile doğrudan arayüz katmanına enjekte olur; arka planda pil tüketmez ve tam thread güvenliği sağlar.

> [!NOTE]
> **Güvenlik Önceliği:** Bu mod yalnızca kullanıcı oturumundaki kilit ekranı arayüz sürecine (`LockApp.exe`) müdahale eder. Güvenli Masaüstü (Secure Desktop) ortamındaki `LogonUI.exe` veya `winlogon.exe` bileşenlerine **asla** dokunmaz; sistem kilitlenme veya güvenlik riski oluşturmaz.

---

## 🎨 Temalar ve Saat Tasarımları

| Saat Stili | Kod | Tasarım ve Estetik Özellikleri | Varsayılan Hizalama |
| :--- | :---: | :--- | :---: |
| 👾 **Retro Piksel / LED Matris** | `pixel` | Otantik 7x11 çift piksel nokta matrisi, sönük arka plan LED ışıması ve buzlu akrilik kontrast paneli. | Merkez |
| ⏳ **Modern Flip Saat** | `flip` | Akrilik buzlu cam kartlar, Fliqlo esintili yatay makas kesiği yaprak yarığı, dolgun oranlar ve 22px kavisli köşeler. | Merkez |
| 📜 **Klasik Flip Saat** | `vintage` | Solari mekanik tren garı tarzı koyu mat kömür flap kartları, fildişi/krem rakamlar, menteşe klipsleri ve yaprak yarığı. | Merkez |
| 🪐 **Minimalist Sonoma** | `macos` | Saatin üzerinde yerel gün/ay başlığı, ultra zarif hafif tipografi, çift katmanlı atmosferik gölge ve estetik sol yerleşim. | Sol-Alt |
| ⚡ **Cyberpunk Sci-Fi HUD** | `cyberpunk` | Koyu obsidyen gövde, asit sarısı ve neon pembe taktiksel köşe braketleri, telemetri teşhis çubuğu ve nabız atan lazer ayraçlar (`//`). | Merkez |
| 🌌 **Minimalist Aura** | `aura` | Kart çerçevesi olmadan, ortam ışığı gölgesi derinliği ve buzlu cam tarih kapsülüyle doğrudan duvar kağıdı üzerinde süzülen tipografi. | Merkez |
| 🪟 **Yalnızca Varsayılan Saat** | `defaultOnly` | Standart Windows 11 saatini korurken hava durumu, haber ve borsa widget kalabalığını tek tıkla gizler. | Standart |

---

## ✨ Öne Çıkan Yetenekler ve Özellikler

- 🔋 **Canlı Akıllı Pil ve Güç Kapsülü:**
  - Canlı dizüstü bilgisayar pil yüzdesini ve şarj durumunu (`⚡` şarj oluyor, `🔋` pil seviyesi) şık bir kapsülde gösterir.
  - Masaüstü bilgisayarlarda kilit ekranını kalabalıklaştırmamak için otomatik olarak gizlenir.
- 🕒 **12 / 24 Saat Zaman Motoru:**
  - Standart 24 saat formatı veya 12 saat AM/PM formatı arasında anında geçiş.
  - Her temaya özel tasarlanmış AM/PM göstergeleri (klasik damga, taktiksel HUD kapsülü veya minimalist metin).
- ⏱️ **Hafızalı Canlı Saniye Göstergesi:**
  - İsteğe bağlı canlı saniye gösterimi (Cyberpunk, Retro Piksel ve Minimalist temalarda desteklenir; mekanik flip saatlerinde otomatik kapalıdır).
  - Her tema için saniye tercihini bağımsız olarak hafızada tutar; temalar arası geçişte tercihler birbirine karışmaz.
- 🛡️ **Tek Saat Koruması ve Otomatik Yeniden Bağlanma:**
  - Windows kilit ekranı görsel ağacını yeniden kurduğunda bunu anında algılar.
  - Eski öğe referanslarını güvenle temizler ve yeni ağaca tek bir saat olarak yeniden bağlanır; çift saat çıkma hatasını engeller.
- 🧵 **Thread Güvenli Reaktif Mimari:**
  - Tüm ayar yüklemeleri, UI yenilemeleri ve kaldırma temizlikleri XAML UI thread'ine (`CoreDispatcher.RunAsync`) aktarılır; veri yarışları (data race) ve çökmeler önlenir.
- 🧹 **MSN Widget ve Kalabalık Temizleyici:**
  - Kilit ekranındaki MSN hava durumu, spor skorları, borsa ve haber kartlarını tek tıkla gizleme olanağı.
- 📐 **Akıllı Temaya Duyarlı Hizalama:**
  - Otomatik (`auto`) hizalama seçeneği Minimalist Sonoma temasını sol-alt köşeye, diğer tüm temaları ise ekranda merkeze yerleştirir. İstenirse elle (`center`, `bottomLeft`, `left`, `right`) değiştirilebilir.

---

## ⚙️ Mod Ayarları Kılavuzu

Tüm ayarlar Windhawk arayüzündeki **Ayarlar (Settings)** sekmesinden kolayca düzenlenebilir:

| Ayar Başlığı | Ayar Anahtarı | Geçerli Değerler / Aralık | Varsayılan | İşlev |
| :--- | :--- | :--- | :---: | :--- |
| **Saat Tasarım Stili** | `clockStyle` | `pixel`, `flip`, `vintage`, `macos`, `cyberpunk`, `aura`, `defaultOnly` | `pixel` | Görüntülenecek saat temasını belirler. |
| **Saat Formatı** | `timeFormat` | `24h`, `12h` | `24h` | 24 Saat veya 12 Saat AM/PM gösterimi. |
| **Saat Yatay Hizalaması** | `clockAlignment` | `auto`, `center`, `bottomLeft`, `left`, `right` | `auto` | Saatin ekran hizalaması (`auto` tema varsayılanını uygular). |
| **Saniyeyi Göster** | `showSeconds` | `true`, `false` | `false` | Canlı saniye sayacı (temaya duyarlı). |
| **Pil Durumu** | `showBatteryStatus`| `true`, `false` | `false` | Dizüstü pil yüzdesi ve şarj durumu kapsülü. |
| **Tarih Kapsülü** | `showDateCapsule` | `true`, `false` | `true` | Saatin altında veya üstünde yerel tarih göstergesi. |
| **Cam Opaklığı** | `glassOpacity` | `0` - `255` | `45` | Buzlu cam kartların yarı saydamlık derecesi. |
| **Rakam Boyutu** | `clockFontSize` | `40` - `160` | `92` | Saat rakamlarının punto büyüklüğü. |
| **Dikey Konum Ofseti** | `verticalOffset` | `-200` ile `+400` px | `0` | Saati ekranda yukarı veya aşağı kaydırma ofseti. |
| **Widget'ları Gizle** | `hideDefaultWidgets`| `true`, `false` | `true` | MSN hava durumu, haber ve borsa widget'larını gizler. |
| **Varsayılan Saati Gizle** | `hideDefaultClock` | `true`, `false` | `true` | Standart Windows 11 saatini gizler. |

---

## 🚀 Kurulum ve Kullanım

1. Henüz yüklü değilse **[Windhawk](https://windhawk.net/)** uygulamasını indirip kurun.
2. Windhawk arayüzünü açın, **Gelişmiş (Advanced)** sekmesine gelin ve **Mod Oluştur (Create Mod)** butonuna tıklayın.
3. [`windows-11-lock-screen-styler.wh.cpp`](./windows-11-lock-screen-styler.wh.cpp) dosyasındaki tüm kaynak kodu kopyalayıp editöre yapıştırın.
4. **Derle (Compile)** (`Ctrl + B`) butonuna basın.
5. Derleme tamamlandıktan sonra modu kaydedip etkinleştirin.
6. <kbd>Win</kbd> + <kbd>L</kbd> tuşlarına basarak kilit ekranını açın ve yeni saatinizin tadını çıkarın!

> [!TIP]
> Modu yeniden derlemenize gerek kalmadan dilediğiniz zaman Windhawk içindeki **Ayarlar** sekmesinden temayı, yazı boyutunu ve hizalamayı anında değiştirebilirsiniz.

---

## 🔒 Güvenlik ve Mimari

- **Hedef Süreç:** Yalnızca `LockApp.exe` sürecine Windows Teşhis Arayüzü (`InitializeXamlDiagnosticsEx`) ile enjekte olur.
- **Güvenli Masaüstü Koruması:** `LogonUI.exe` ve `winlogon.exe` gibi oturum açma ve kimlik doğrulama süreçlerine kesinlikle müdahale etmez. Parola giriş ekranınız tamamen korunur.
- **Düşük Kaynak Tüketimi:** Akıllı önbellek mimarisi sayesinde ekran açıkken saniyede bir kez hafifçe güncellenir; ekran kilidi kapandığında veya varsayılan saat modunda zamanlayıcı otomatik durdurularak sıfır işlemci ve pil tüketimi sağlanır.
- **Geniş Uyumluluk:** Windows 11 **23H2**, **24H2** ve **25H2** (Build 26200+) sürümlerinde kapsamlı olarak test edilmiştir.

---

## 📄 Lisans

Bu proje [MIT Lisansı](LICENSE) kapsamında sunulmaktadır &copy; 2026 [ali0zdas](https://github.com/ali0zdas).
