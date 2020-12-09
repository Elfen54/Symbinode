#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QQuickWindow>
#include "tab.h"
#include "clipboard.h"
#include "noisenode.h"
#include "mixnode.h"
#include "albedonode.h"
#include "metalnode.h"
#include "roughnode.h"
#include "normalmapnode.h"
#include "normalnode.h"
#include "voronoinode.h"
#include "polygonnode.h"
#include "circlenode.h"
#include "transformnode.h"
#include "tilenode.h"
#include "warpnode.h"
#include "blurnode.h"
#include "inversenode.h"
#include "colorrampnode.h"
#include "colornode.h"
#include "coloringnode.h"
#include "mappingnode.h"
#include "splatnode.h"
#include "mirrornode.h"
#include "brightnesscontrastnode.h"
#include "thresholdnode.h"

class MainWindow: public QQuickWindow
{
    Q_OBJECT
    Q_PROPERTY(Node* activeNode READ activeNode)
    Q_PROPERTY(Node* pinnedNode READ pinnedNode)
public:
    Q_INVOKABLE void createNode(float x, float y, int nodeType);
    Q_INVOKABLE void newDocument();
    Q_INVOKABLE void copy();
    Q_INVOKABLE void paste();
    Q_INVOKABLE void cut();
    Q_INVOKABLE void deleteItems();
    Q_INVOKABLE void saveScene();
    Q_INVOKABLE void saveSceneAs();
    Q_INVOKABLE void loadScene();
    Q_INVOKABLE void exportTextures();
    Q_INVOKABLE void changeResolution(QVector2D res);
    Q_INVOKABLE void changePrimitive(int id);
    Q_INVOKABLE void changeTilePreview3D(int id);
    Q_INVOKABLE void undo();
    Q_INVOKABLE void redo();
    Q_INVOKABLE void pin(bool pinned);
    MainWindow(QWindow *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
    void duplicate();
    void setActiveTab(Tab *tab);
    void closeTab(Tab *tab);
    Node *pinnedNode();
    Node *activeNode();
    void activeNodeChanged();

signals:
    void addTab(Tab *tab);
    void deleteTab(Tab *tab);
    void propertiesPanelChanged(QQuickItem *oldPanel, QQuickItem *newPanel);
    void preview3DChanged(QQuickItem *oldPreview, QQuickItem *newPreview);
    void previewUpdate(QVariant previewData, bool useTexture);
    void resolutionChanged(QVector2D res);
private:
    Tab *activeTab = nullptr;
    Node *m_activeNode = nullptr;
    Node *m_pinnedNode = nullptr;
    QList<Tab*> tabs;
    Clipboard *m_clipboard = nullptr;
};

#endif // MAINWINDOW_H