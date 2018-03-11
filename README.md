<h1 align="center">Утилиты, команды, ошибки Linux</h1>

В boot разделе мало места.
</br>1) Удалить образы старых ядер:
```
dpkg -l|grep linux-image //список образов
aptitude remove linux-image<версия ядра> //удаление ядра
aptitude purge linux-image<версия ядра> //удаление ядра из конфига
```
2) Перенести /boot с выделенного раздела на корневой системы /
```
mount /dev/sda1 /mnt/
umount /boot/
cp -p -r /mnt/* /boot/
update-grub

leafpad /etc/fstab //закоментировать или удалить строчку в fstab с разделом boot:
```

</br></br></br>
Блокировка __/var/lib/dpkg/__
```
E: Не удалось получить доступ к файлу блокировки /var/lib/dpkg/lock - open (11: Ресурс временно недоступен)
E: Не удалось выполнить блокировку управляющего каталога (/var/lib/dpkg/); он уже используется другим процессом?
```
Хорошо, что можно разблокировать каталог всего одной командой. А избавиться от этой проблемы просто, достаточно выполнить команду:
```
sudo fuser -vki /var/lib/dpkg/lock
```

</br></br></br>
### chmod
```
chmod [ключ] [режим модификатор права] [файл]
```
___режим:___ __u__ - владелец, __g__ - группа, __o__ - остальные, __a__ - все пользователи системы
</br>___модификатор:___ __-__ лишить, __+__ добать, __=__ установить указанные вместо имеющихся
</br>___права:___ __r__ - чтение, __w__ - запись, __x__ - исполнение
```
chmod ugoa+rwx /home
```
__ключи:__
</br>-R рекурсивно изменить права для файлов и папок `chmod -R ugoa+rwx /home`


</br></br></br>
### OpenGL
Ссылки по работе с библиотекой:
</br>~~[linuxcenter - Qt/OpenGL](http://www.linuxcenter.ru/lib/books/opengl/_index "OpenGL. Программирование графики в Linux")~~
</br>[Уроки по OpenGL с сайта OGLDev](http://triplepointfive.github.io/ogltutor/ "http://triplepointfive.github.io/ogltutor/")
