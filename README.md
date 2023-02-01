# Operating-Systems-Project
Konu: Ana process’in yanı sıra N adet child process oluşturabilecek bir program tasarlayınız. N adet child process ile içerisinde birçok integer sayı bulunan N adet dosya içerisindeki k. en büyük sayıyı buldurma işlemi yapılacaktır. N adet girdi dosyası aynı anda N işlem tarafından işlenecektir. Her bir girdi dosyası çok büyük sayıda pozitif integer değerler içerebilir. Output dosyasına yazılacak olan sonuçlar büyükten küçüğe doğru sıralanmış olacaktır. K 1 ile 1000 arasında bir sayı olabilir. N değeri 1 ve 5 arasında bir sayı olabilir. Input ve output dosyaları ASCII text dosyaları olacaktır. Program aşağıdaki şekilde çağrılacaktır:
findtopk <k> <N> <infile1> ...<infileN> <outfile>
Her bir child process bir adet input dosyasını okuyacak ve işleyecektir. İşlenen dosya intermediate (ara) dosyaya yazacaktır. Tüm child işlemler bittiği zaman ana process bu intermediate dosyaları okuyup işleyecektir. 
Her seferinde yalnızca bir girdi dosyasından bir (veya iki) karakter okuyabilirsiniz. Input dosyaları içerisinde boşluk karakterleri ile (space,tab,newline) ile ayrılmış sayılar içermektedir. Output dosyasında her bir satırda yalnızca bir integer değer olmalıdır. Tüm işlemler bittiğinde intermediate dosyalar program tarafından silinmelidir. Make yazdığımız zaman tüm programlarınız compile edilebilmeli ve ilgili exe’ler üretilmelidir.

Açıklama:
Program Ubuntu'da yapılmıştır.
Sayıların bulunduğu dosyalar Makefile dosyasının içinde dışarıdan parametre gönderilmiştir
Ben 3 adet dosya ve her dosyada 1000 adet sayı olacak şekilde yaptım. Eğer daha fazla dosyayla yapılmak isteniyorsa içinde sayılar bulunan infile dosyaları projeye dahil edilmeli ve Makefile dosyasının içine parametre olarak dosyanın adı yazılmalıdır.
"k.en büyük sayı"daki k değeri de Makefile'dan parametre olarak gönderilmiştir. k'yı değiştirmek isterseniz Makefile'ın içini değiştirin.
"Make run" yazarak program çalıştırılabilir.
