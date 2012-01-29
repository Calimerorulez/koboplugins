#ifndef __HOME_MENU_CONTROLLER_H__
#define __HOME_MENU_CONTROLLER_H__


class GestureDelegate {
};

class GestureReceiver {
public:
    void setGestureDelegate(GestureDelegate *);
    GestureDelegate *gestureDelegate();
};

class AbstractMenuController : public QObject, public GestureDelegate {
    Q_OBJECT
public:
    void addWidgetAction(QMenu *, QWidget *, char const *, bool, bool);
    void addWidgetActionWithMapper(QMenu *, QWidget *, QSignalMapper *, QString, bool, bool);
    void grabTapGesture(GestureReceiver *);
public slots:
    void show();
};


class MenuTextItem : public QWidget, public GestureReceiver {
public:
    void setSelectedImage(const QString &);
    void setSelected(bool);
    QString &text();
    void setText(const QString& t);
};

class AbstractNickelMenuController : public AbstractMenuController {
public:
    MenuTextItem * createMenuTextItem(QMenu *, const QString &, bool);
};

enum DecorationPosition { ONE };

class TouchMenu : public QMenu {
public:
    TouchMenu(QString const&, QWidget *);
    void initialize();
};

class NickelTouchMenu : public TouchMenu {
public:
    NickelTouchMenu(QWidget*, DecorationPosition);
};

class HomeMenuController : public AbstractNickelMenuController {
public:
    void store();
	void settings();
	void dictionary();
	void library();
    void readingLife();
    void sync();
    void help();
};

class ReversibleLabel : public QWidget
{
	public:
		ReversibleLabel(QWidget* p = NULL);
};

class TouchLabel : public QWidget
{
	public:
};

class LibraryMenuController : public QObject
    {
    public:
        void favourites();
		void search();
    };

#endif // __HOME_MENU_CONTROLLER_H__

