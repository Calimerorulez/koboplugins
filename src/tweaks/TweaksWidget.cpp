#include "TweaksWidget.h"
#include <iostream>
#include "LedManager.h"
#include "TweaksPlugin.h"
#include "config.h"

using namespace std;

TweaksWidget::TweaksWidget(TweaksPlugin *plugin, QWidget *parent=0)
    : QWidget(parent),
    plugin(plugin)
{
    setupUi(this);

    cout << "TweaksWidget()" << endl << flush; 
    PluginsConfig* pConfig = PluginsConfig::get();

    browserShortcut->setChecked(pConfig->value("Menu/showBrowser", true).toBool());
    wifiTimeout->setChecked(pConfig->value("Tweaks/enableWirelessTimeout", true).toBool());
    hideRecommendations->setChecked(pConfig->value("Tweaks/hideRecommendations", false).toBool());
    cout << "TweaksWidget()" << endl << flush; 

    QWidget::setAttribute(Qt::WA_AcceptTouchEvents);
    redOn->setAttribute(Qt::WA_AcceptTouchEvents);
    redOff->setAttribute(Qt::WA_AcceptTouchEvents);
    greenOn->setAttribute(Qt::WA_AcceptTouchEvents);
    greenOff->setAttribute(Qt::WA_AcceptTouchEvents);
    blueOn->setAttribute(Qt::WA_AcceptTouchEvents);
    blueOff->setAttribute(Qt::WA_AcceptTouchEvents);
    browserShortcut->setAttribute(Qt::WA_AcceptTouchEvents);
    wifiTimeout->setAttribute(Qt::WA_AcceptTouchEvents);
    hideRecommendations->setAttribute(Qt::WA_AcceptTouchEvents);
    syncButton->setAttribute(Qt::WA_AcceptTouchEvents);
    uninstallButton->setAttribute(Qt::WA_AcceptTouchEvents);

    connect(redOn, SIGNAL(pressed()), this, SLOT(redLedOn()));
    connect(redOff, SIGNAL(pressed()), this, SLOT(redLedOff()));
    connect(greenOn, SIGNAL(pressed()), this, SLOT(greenLedOn()));
    connect(greenOff, SIGNAL(pressed()), this, SLOT(greenLedOff()));
    connect(blueOn, SIGNAL(pressed()), this, SLOT(blueLedOn()));
    connect(blueOff, SIGNAL(pressed()), this, SLOT(blueLedOff()));
    connect(browserShortcut, SIGNAL(toggled(bool)), plugin, SLOT(enableBrowserShortcut(bool)));
    connect(wifiTimeout, SIGNAL(toggled(bool)), plugin, SLOT(enableWirelessTimeout(bool)));
    connect(hideRecommendations, SIGNAL(toggled(bool)), plugin, SLOT(hideRecommendations(bool)));
    connect(syncButton, SIGNAL(clicked(bool)), plugin, SLOT(sync(bool)));
	connect(uninstallButton, SIGNAL(clicked()), plugin, SLOT(uninstallPlugin()));
}

bool TweaksWidget::event(QEvent* event) {
    cout << "TweaksWidget::event " << event->type() << endl << flush;
    return QWidget::event(event);
}

void TweaksWidget::redLedOn()
{
    LedManager::sharedInstance()->redOn();
}

void TweaksWidget::redLedOff()
{
    LedManager::sharedInstance()->redOff();
}

void TweaksWidget::greenLedOn()
{
    LedManager::sharedInstance()->greenOn();
}

void TweaksWidget::greenLedOff()
{
    LedManager::sharedInstance()->greenOff();
}

void TweaksWidget::blueLedOn()
{
    LedManager::sharedInstance()->blueOn();
}

void TweaksWidget::blueLedOff()
{
    LedManager::sharedInstance()->blueOff();
}

void TweaksWidget::onResume()
{
    cout << "Kobo onResume()" << endl << flush; 
    //emit setHeaderText("TweaksWidget::onResume()");
    //emit openFooterMenu();
}

void TweaksWidget::goToNextPage()
{
    cout << "Kobo goToNextPage() " << endl << flush;
    emit closeFooterMenu();
}

void TweaksWidget::goToPrevPage()
{
    cout << "Kobo goToPrevPage() " << endl << flush;
    emit setHeaderText("Hello Kobo: PrevPage");
    emit openFooterMenu();
}

void TweaksWidget::onDisplayMenuRequested(QList<PluginInterface::MenuGroup>&)
{
    cout << "Kobo onDisplayMenuRequested() " << endl << flush;
}

void TweaksWidget::displayTitlePage()
{
    cout << "Kobo displayTitlePage() " << endl << flush;
}

void TweaksWidget::homeKeyPressed()
{
    cout << "Kobo homeKeyPressed() " << endl << flush;
}
