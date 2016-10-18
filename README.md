# Ошибки, утилиты, команды Linux

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

