# Windows 11 Kilit Ekranı Özelleştirici (Lock Screen Styler)

Windows 11 kilit ekranını (`LockApp.exe`) modern saat tasarımları, akrilik/buzlu cam kartlar, dinamik tarih kapsülü ve widget gizleme seçenekleriyle özelleştiren bir [Windhawk](https://windhawk.net/) modudur.

[English Readme](README.md)

---

## ✨ Özellikler

- **Modern Flip Saat:** Saat ve dakika için bölünmüş, kareye yakın dolgun oranları, ortasında şık makas kesiği yarığı ve 24px kavisli köşeleri bulunan akrilik cam kartlar.
- **Klasik Flip Saat:** Klasik mekanik Solari tren garı / havalimanı esintili koyu mat kömür kartlar, fildişi/krem rakamlar, kareye yakın oranlar, belirgin mekanik katlanma yarığı ve menteşe klipsleri.
- **Cyberpunk Bilim Kurgu HUD Terminali:** Koyu obsidyen gövde, asit sarısı ve neon pembe taktiksel köşe braketleri, üst telemetri tanı çubuğu, lazer eğik çizgi ayracı (`//`) ve alt tarih günlüğüyle özgün Netrunner HUD arayüzü.
- **Minimalist Aura / Yüzen Saat:** Kart çerçevesi olmadan, ortam ışığı gölgesi (ambient drop-shadow) derinliği ve buzlu cam tarih kapsülüyle doğrudan duvar kağıdı üzerinde süzülen zarif tipografi.
- **Retro Piksel / LED Matris Saat:** Otantik 7x11 çift piksel (çift nokta) kalınlığında nokta matris ekranı, sönük arka plan LED ışıması ve ferah dikey yüksekliğe sahip buzlu akrilik kontrast paneli.
- **12 / 24 Saat Formatı:** 24 saat gösterimi veya temalara özel tasarlanmış şık AM/PM rozetleriyle 12 saat formatı arasında geçiş imkanı.
- **Saniye Göstergesi:** Canlı saniye gösterimi açıp kapatma (Cyberpunk HUD, Retro Pixel ve Aura stillerinde desteklenir).
- **Dinamik Tarih Kapsülü:** Saatin altında konumlanan, sistem diline duyarlı gün ve ay göstergesi.
- **Varsayılan Kalabalığı Gizleme:** Kilit ekranındaki MSN hava durumu, spor, borsa ve haber widget'larını tek tıkla gizleme imkanı.
- **Varsayılan Saati Değiştirme:** Windows 11'in standart kilit ekranı saatini gizleyip yerine özel tasarımı getirme.
- **Geniş Özelleştirilebilirlik:** Cam opaklığı, font boyutu, hizalama ve dikey ofset gibi detayları ayarlar sekmesinden düzenleme.
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
| **Clock Style (Saat Stili)** | Retro Piksel LED Matris (`pixel`), Modern Flip Saat (`flip`), Klasik Flip Saat (`vintage`), Minimalist Aura Yüzen Saat (`aura`), Cyberpunk HUD Terminali (`cyberpunk`) veya Varsayılan Saat (`defaultOnly`) seçimi | `flip` |
| **Time Format (Saat Formatı)** | 24 Saat (`24h`) veya 12 Saat AM/PM (`12h`) formatı | `24h` |
| **Show Seconds (Saniyeyi Göster)** | Canlı saniye göstergesini açıp kapatma (Cyberpunk, Retro Pixel ve Aura) | `Kapalı` |
| **Glass Opacity (Cam Opaklığı)** | Kartların yarı saydamlık derecesi (0 - 255) | `45` |
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
