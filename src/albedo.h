/*
 * Copyright © 2020 Gukova Anastasiia
 * Copyright © 2020 Gukov Anton <fexcron@gmail.com>
 *
 *
 * This file is part of Symbinode.
 *
 * Symbinode is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Symbinode is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Symbinode.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef ALBEDO_H
#define ALBEDO_H
#include <QQuickFramebufferObject>
#include <QOpenGLFunctions_4_4_Core>
#include <QOpenGLShaderProgram>
#include "FreeImage.h"

class AlbedoObject: public QQuickFramebufferObject
{
    Q_OBJECT
public:
    AlbedoObject(QQuickItem *parent = nullptr, QVector2D resolution = QVector2D(1024, 1024));
    QQuickFramebufferObject::Renderer *createRenderer() const;
    QVariant albedo();
    void setAlbedo(QVariant albedo);
    void setColorTexture(unsigned int texture);
    void setAlbedoTexture(unsigned int texture);
    unsigned int &texture();
    void saveTexture(QString fileName);
    QVector2D resolution();
    void setResolution(QVector2D res);
    bool useAlbedoTex = false;
    bool selectedItem = false;
    bool texSaving = false;
    QString saveName = "";
signals:
    void updatePreview(unsigned int previewData);
    void updateAlbedo(QVariant albedo, bool useTexture);
private:
    unsigned int m_colorTexture = 0;
    unsigned int m_albedoTexture = 0;
    QVariant m_albedo = QVector3D(1.0f, 1.0f, 1.0f);
    QVector2D m_resolution;
};

class AlbedoRenderer: public QQuickFramebufferObject::Renderer, public QOpenGLFunctions_4_4_Core {
public:
    AlbedoRenderer(QVector2D resolution);
    ~AlbedoRenderer();
    QOpenGLFramebufferObject *createFramebufferObject(const QSize &size);
    void synchronize(QQuickFramebufferObject *item);
    void render();
private:
    void saveTexture(QString fileName);
    void createColor();
    QOpenGLShaderProgram *renderAlbedo;
    unsigned int VAO = 0;
    unsigned int colorFBO = 0;
    unsigned int albedoTexture = 0;
    unsigned int colorTexture = 0;
    QVector3D albedoVal = QVector3D(1.0f, 1.0f, 1.0f);
    QVector2D m_resolution;
};

#endif // ALBEDO_H
