<div align="center">

# 🔒 Kilit Ekranı Saat Özelleştirici (Lock Screen Clock Styler)

**Windows 11 kilit ekranı saatinizi modern tasarımlar, akrilik buzlu cam paneller, canlı pil telemetrisi ve temiz yerleşim denetimleriyle baştan yaratın.**

[![Windhawk Mod](https://img.shields.io/badge/Windhawk-Mod-00A4EF?style=for-the-badge&logo=windows11&logoColor=white)](https://windhawk.net/)
[![Windows 11](https://img.shields.io/badge/Windows_11-24H2_%7C_25H2_%7C_26H2-0078D4?style=for-the-badge&logo=windows&logoColor=white)](https://www.microsoft.com/windows)
[![C++20 / C++/WinRT](https://img.shields.io/badge/C%2B%2B-20_%2F_WinRT-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://docs.microsoft.com/en-us/windows/uwp/cpp-and-winrt-apis/)
[![Sürüm](https://img.shields.io/badge/S%C3%BCr%C3%BCm-0.5.0-success?style=for-the-badge)](https://github.com/ali0zdas/windhawk-mod-lock-screen-clock-styler/releases)
[![Lisans: MIT](https://img.shields.io/badge/Lisans-MIT-yellow.svg?style=for-the-badge)](LICENSE)

<br/>

**[ English ](README.md)** &nbsp;&bull;&nbsp; **[ 🇹🇷 Türkçe ](README-TÜRKÇE.md)**

---

</div>

## 🌟 Genel Bakış

**Lock Screen Clock Styler**, Windows 11 kilit ekranı uygulamasını (`LockApp.exe`) zenginleştirmek ve özelleştirmek için geliştirilmiş yerel ve yüksek performanslı bir [Windhawk](https://windhawk.net/) modudur.

Standart Windows kilit ekranı saatini ve kalabalık MSN haber/widget kartlarını gizleyerek yerine 6 farklı özel tasarım saat estetiği getirir: Apple macOS Sonoma tipografisi, çift yapraklı Fliqlo tarzı buzlu cam flip saat, Solari mekanik tren garı saati, otantik 7x11 retro LED nokta matrisi ve taktiksel Cyberpunk HUD terminali. **C++/WinRT** ile geliştirilmiştir; kilit ekranı görsel ağacını doğrudan LockApp'in kendi UI thread'inden keşfeder, özel XAML öğelerini arayüz katmanına enjekte eder ve XAML `DispatcherTimer` kullanmadan tam thread güvenliği sağlar.

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
| 🪟 **Yalnızca Varsayılan Saat** | `defaultOnly` | Standart Windows 11 saatini korur. Widget gizleme, kendi anahtarından ayrıca açılabilir. | Standart |

---

## 📸 Ekran Görüntüleri

<p align="center">
  <img src="https://raw.githubusercontent.com/ali0zdas/windhawk-mod-lock-screen-clock-styler/main/screenshots/Retro%20Pixel.png" width="49%" alt="Retro Piksel / LED Matris" />
  <img src="https://raw.githubusercontent.com/ali0zdas/windhawk-mod-lock-screen-clock-styler/main/screenshots/modern%20flip%20clock.png" width="49%" alt="Modern Flip Saat" />
  <br />
  <img src="https://raw.githubusercontent.com/ali0zdas/windhawk-mod-lock-screen-clock-styler/main/screenshots/classical%20flip%20clock.png" width="49%" alt="Klasik Flip Saat" />
  <img src="https://raw.githubusercontent.com/ali0zdas/windhawk-mod-lock-screen-clock-styler/main/screenshots/sonoma.png" width="49%" alt="Minimalist Sonoma" />
  <br />
  <img src="https://raw.githubusercontent.com/ali0zdas/windhawk-mod-lock-screen-clock-styler/main/screenshots/cyberpunk%20style.png" width="49%" alt="Cyberpunk Sci-Fi HUD" />
</p>

> Windows 11 (24H2 / 25H2) üzerinde alınmıştır.

---

## ✨ Öne Çıkan Yetenekler ve Özellikler

- 🔋 **Canlı Akıllı Pil ve Güç Kapsülü:**
  - Canlı dizüstü bilgisayar pil yüzdesini ve şarj durumunu (`⚡` şarj oluyor, `🔋` pil seviyesi) şık bir kapsülde gösterir.
  - Masaüstü bilgisayarlarda kilit ekranını kalabalıklaştırmamak için otomatik olarak gizlenir.
- 🕒 **12 / 24 Saat Zaman Motoru:**
  - Standart 24 saat formatı veya 12 saat AM/PM formatı arasında anında geçiş.
  - Her temaya özel tasarlanmış AM/PM göstergeleri (klasik damga, taktiksel HUD kapsülü veya minimalist metin).
- ⏱️ **Canlı Saniye Göstergesi:**
  - İsteğe bağlı canlı saniye gösterimi; iki mekanik flip saat dışındaki tüm stillerde desteklenir.
  - Ayardaki anahtar tek doğruluk kaynağıdır; stil değiştirildiğinde eski temaya ait saniye tercihi takılı kalmaz.
- 🛡️ **Tek Saat Koruması ve Otomatik Yeniden Bağlanma:**
  - Kilit ekranı görsel ağacını düzenli aralıklarla yeniden tarar ve Windows ağacı yeniden kurduğunda saati güvenle yeniden enjekte eder.
  - Yeni saati eklemeden önce eski saati kaldırır; çift saat çıkma hatasını engeller.
- 🧵 **Thread Güvenli UI Dağıtımı:**
  - Güncellemeleri kilit ekranı UI thread'indeki bir `WH_GETMESSAGE` hook'u yürütür; tüm XAML okuma ve yazmaları bu thread'de kalır.
  - Ayar yenilemeleri ve kaldırma temizliği `WH_CALLWNDPROC` mesajıyla senkron olarak UI thread'ine gönderilir; DLL kaldırılırken mod kodunun çalışır durumda kalması önlenir.
- 🧩 **XAML Diagnostics TAP Kullanmaz:**
  - Kilit ekranı ağacını XAML Diagnostics TAP kaydı yerine `Window::Current().Content()` ve `VisualTreeHelper` ile bulur.
  - Windows 11 Başlat Menüsü Stil Verici gibi diğer XAML tabanlı Windhawk modlarıyla birlikte çalışabilir.
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
| **Saniyeyi Göster** | `showSeconds` | `true`, `false` | `true` | Canlı saniye (yalnızca `flip` ve `vintage` dışındaki stiller). |
| **Pil Durumu** | `showBatteryStatus`| `true`, `false` | `false` | Dizüstü pil yüzdesi ve şarj durumu kapsülü. |
| **Tarih Kapsülü** | `showDateCapsule` | `true`, `false` | `true` | Saatin altında veya üstünde yerel tarih göstergesi. |
| **Cam Opaklığı** | `glassOpacity` | `0` - `255` | `45` | Modern Flip kartlarının yarı saydamlığı. |
| **Rakam Boyutu** | `clockFontSize` | `20` - `300` | `140` | Saat rakamlarının temel punto büyüklüğü. |
| **Dikey Konum Ofseti** | `verticalOffset` | `-200` ile `+400` px | `0` | Saati ekranda yukarı veya aşağı kaydırma ofseti. |
| **Widget'ları Gizle** | `hideDefaultWidgets`| `true`, `false` | `false` | MSN hava durumu, haber ve borsa widget'larını gizler. |
| **Varsayılan Saati Gizle** | `hideDefaultClock` | `true`, `false` | `true` | Standart Windows 11 saatini gizler. |

---

## 🚀 Kurulum ve Kullanım

1. Henüz yüklü değilse **[Windhawk](https://windhawk.net/)** uygulamasını indirip kurun.
2. Windhawk arayüzünü açın, **Gelişmiş (Advanced)** sekmesine gelin ve **Mod Oluştur (Create Mod)** butonuna tıklayın.
3. [`lock-screen-clock-styler.wh.cpp`](./lock-screen-clock-styler.wh.cpp) dosyasındaki tüm kaynak kodu kopyalayıp editöre yapıştırın.
4. **Derle (Compile)** (`Ctrl + B`) butonuna basın.
5. Derleme tamamlandıktan sonra modu kaydedip etkinleştirin.
6. <kbd>Win</kbd> + <kbd>L</kbd> tuşlarına basarak kilit ekranını açın ve yeni saatinizin tadını çıkarın!

> [!TIP]
> Modu yeniden derlemenize gerek kalmadan dilediğiniz zaman Windhawk içindeki **Ayarlar** sekmesinden temayı, yazı boyutunu ve hizalamayı anında değiştirebilirsiniz.

---

## 🔒 Güvenlik ve Mimari

- **Hedef Süreç:** Yalnızca `LockApp.exe` sürecine enjekte olur; `Windows.UI.Core.CoreWindow` thread'ine mesaj hook'u kurar ve görsel ağacı bu UI thread'inden tarar. XAML Diagnostics TAP kaydı yapılmaz.
- **Güvenli Masaüstü Koruması:** `LogonUI.exe` ve `winlogon.exe` gibi oturum açma ve kimlik doğrulama süreçlerine kesinlikle müdahale etmez. Parola giriş ekranınız tamamen korunur.
- **Düşük Kaynak Tüketimi:** Polling zamanlayıcısı yerine mesaj güdümlü güncelleme kullanır (saniye açıkken 500 ms, aksi halde 1000 ms). Varsayılan saat modunda hiçbir saat çizimi yapılmaz.
- **Geniş Uyumluluk:** Windows 11 **24H2**, **25H2** ve **26H2** (Build 26200+) sürümlerinde kapsamlı olarak test edilmiştir. TAP kullanmayan tasarımı sayesinde diğer XAML tabanlı Windhawk modlarıyla birlikte çalışabilir.

---

## 🤝 Katkıda Bulunma ve Geri Bildirim

Geri bildirimler, hata bildirimleri ve yeni tema önerileri modun gelişimi için çok değerlidir! Yeni bir saat stili fikriniz varsa, bir hatayla karşılaştıysanız veya koda katkı sunmak isterseniz:
- [GitHub deposu](https://github.com/ali0zdas/windhawk-mod-lock-screen-clock-styler) üzerinde yeni bir issue veya pull request açabilirsiniz.
- Eklenmesini istediğiniz estetik saat tasarımlarını bize iletebilirsiniz!

---

## 📄 Lisans

Bu proje [MIT Lisansı](LICENSE) kapsamında sunulmaktadır &copy; 2026 [ali0zdas](https://github.com/ali0zdas).
