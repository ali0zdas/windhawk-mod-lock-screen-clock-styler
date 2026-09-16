# Windows 11 Kilit Ekranı Özelleştirici (Lock Screen Styler)

Windows 11 kilit ekranını (`LockApp.exe`) modern saat tasarımları, akrilik/buzlu cam kartlar, dinamik tarih kapsülü ve widget gizleme seçenekleriyle özelleştiren bir [Windhawk](https://windhawk.net/) modudur.

[English Readme](README.md)

---

## ✨ Özellikler

- **Modern Flip Clock:** Saat ve dakika için bölünmüş, ortasında şık katlanma çizgisi bulunan akrilik cam kartlar.
- **Retro Vintage Flip Saat:** Klasik mekanik Solari tren garı / havalimanı esintili koyu mat kömür kartlar, fildişi/krem rakamlar, belirgin mekanik katlanma yarığı ve menteşe klipsleri.
- **Cyberpunk / Neon Glow Saat:** Koyu obsidyen akrilik kartlar, elektrik camgöbeği (cyan) neon kenar ışıması, lazer kesim ayrım çizgisi ve parlak macenta/pembe HUD tarih kapsülü.
- **Retro Piksel / LED Matris Saat:** Otantik 7x9 çift piksel (çift nokta) kalınlığında nokta matris ekranı, sönük arka plan LED ışıması ve buzlu akrilik kontrast paneli.
- **Saniye Göstergesi:** İsteğe bağlı olarak saat ve dakikayla aynı hizada tam format (`SS:DD:SN`) gerçek zamanlı saniye gösterimi.
- **Dinamik Tarih Kapsülü:** Saatin altında konumlanan, sistem diline duyarlı gün ve ay göstergesi.
- **Varsayılan Kalabalığı Gizleme:** Kilit ekranındaki MSN hava durumu, spor, borsa ve haber widget'larını tek tıkla gizleme imkanı.
- **Varsayılan Saati Değiştirme:** Windows 11'in standart kilit ekranı saatini gizleyip yerine özel tasarımı getirme.
- **Geniş Özelleştirilebilirlik:** Cam opaklığı, kart köşe yuvarlaklığı, font boyutu, hizalama ve dikey ofset gibi tüm detayları ayarlar sekmesinden düzenleme.
- **Çoklu Dil Desteği:** Windhawk içinde yerleşik İngilizce ve Türkçe (`tr-TR`) arayüz metinleri.

---

## 🛠️ Nasıl Kurulur ve Kullanılır?

1. [Windhawk](https://windhawk.net/) uygulamasını indirip açın.
2. **Gelişmiş (Advanced)** -> **Mod Oluştur (Create Mod)** sekmesine gidin (veya resmi katalogda yayınlandıktan sonra doğrudan arayın).
3. [`windows-11-lock-screen-styler.wh.cpp`](./windows-11-lock-screen-styler.wh.cpp) dosyasının içeriğini editöre yapıştırın.
4. **Derle (Compile)** (`Ctrl + B`) butonuna basın ve modu kaydedip etkinleştirin.
5. Modu test etmek için bilgisayarınızı kilitleyin (**`Win + L`**).

---

## ⚙️ Mod Ayarları

| Ayar | Açıklama | Varsayılan |
| :--- | :--- | :--- |
| **Clock Style (Saat Stili)** | Buzlu Cam Flip Saat (`flip`), Retro Vintage Flip Saat (`vintage`), Cyberpunk Neon Glow (`cyberpunk`), Retro Piksel LED Matris (`pixel`), Minimal Dijital (`minimal`) veya Varsayılan Saat (`defaultOnly`) seçimi | `flip` |
| **Show Seconds (Saniyeyi Göster)** | Saniye hanesini açıp kapatma (`SS:DD:SN`) | `Kapalı` |
| **Glass Opacity (Cam Opaklığı)** | Kartların yarı saydamlık derecesi (0 - 255) | `45` |
| **Card Corner Radius (Köşe Yuvarlaklığı)**| Kartların köşe kavis yarıçapı (px) | `22` |
| **Digit Font Size (Font Boyutu)** | Saat ve dakika rakamlarının punto büyüklüğü | `92` |
| **Vertical Offset (Dikey Ofset)** | Saati yukarı veya aşağı kaydırma ofseti (-200 ile +400 px) | `0` |
| **Clock Alignment (Yatay Hizalama)** | Saatin ekrandaki yatay hizalaması (`center`, `left`, `right`) | `center` |
| **Hide Default Widgets (Widget Gizle)** | MSN hava durumu, haber ve finans alanını gizler | `Etkin` |
| **Hide Default Clock (Saati Gizle)** | Standart Windows 11 saat ve tarihini gizler | `Etkin` |
| **Show Date Capsule (Tarih Kapsülü)** | Kartların altında gün ve ay kapsülünü görüntüler | `Etkin` |

---

## 🔒 Güvenlik ve Uyumluluk

- Yalnızca kilit ekranı arayüz sürecine (`LockApp.exe`) müdahale eder.
- Güvenli Masaüstü (Secure Desktop) ortamındaki `LogonUI.exe` ve `winlogon.exe` süreçlerine dokunmaz, sistem kilitlenme riski oluşturmaz.
- Windows 11 ile tam uyumludur (Windows 11 23H2 / 24H2 / 25H2 sürümlerinde test edilmiştir).

---

## 📄 Lisans

Bu proje [MIT Lisansı](LICENSE) altında sunulmaktadır.
