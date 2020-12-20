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

import QtQuick 2.12
import QtQuick.Controls 2.5

Item {
    width: parent.width
    height: childrenRect.height + 45
    property alias startNoiseScale: scaleParam.propertyValue
    property alias startScaleX: scaleXParam.propertyValue
    property alias startScaleY: scaleYParam.propertyValue
    property alias startLayers: layersParam.propertyValue
    property alias startPersistence: persistenceParam.propertyValue
    property alias startAmplitude: amplitudeParam.propertyValue
    property alias startSeed: seedParam.propertyValue
    property alias type: control.currentIndex
    signal noiseTypeChanged(string type)
    signal noiseScaleChanged(real scale)
    signal scaleXChanged(real scale)
    signal scaleYChanged(real scale)
    signal layersChanged(int layers)
    signal persistenceChanged(real persistence)
    signal amplitudeChanged(real aplitude)
    signal seedChanged(int seed)

    ParamDropDown {
        id: control
        y: 15
        onActivated: {
            if(index == 0) {
                noiseTypeChanged("noisePerlin")
            }
            else if(index == 1) {
                noiseTypeChanged("noiseSimple")
            }
            focus = false
        }
    }
    ParamSlider {
        id: scaleParam
        y: 38
        propertyName: "Scale"
        maximum: 100
        step: 1
        onPropertyValueChanged: {
            noiseScaleChanged(scaleParam.propertyValue)
        }
    }
    ParamSlider {
        id: scaleXParam
        y: 71
        propertyName: "Scale X"
        step: 1
        minimum: 1
        maximum: 20
        onPropertyValueChanged: {
            scaleXChanged(scaleXParam.propertyValue)
        }
    }
    ParamSlider {
        id: scaleYParam
        y: 104
        propertyName: "Scale Y"
        step: 1
        minimum: 1
        maximum: 20
        onPropertyValueChanged: {
            scaleYChanged(scaleYParam.propertyValue)
        }
    }
    ParamSlider {
        id: layersParam
        y: 137
        propertyName: "Layers"
        maximum: 16
        step: 1
        onPropertyValueChanged: {
            layersChanged(layersParam.propertyValue)
        }
    }
    ParamSlider {
        id: persistenceParam
        y: 170
        propertyName: "Persistence"
        onPropertyValueChanged: {
            persistenceChanged(persistenceParam.propertyValue)
        }
    }
    ParamSlider {
        id: amplitudeParam
        y: 203
        propertyName: "Amplitude"
        onPropertyValueChanged: {
            amplitudeChanged(amplitudeParam.propertyValue)
        }
    }
    ParamSlider {
        id: seedParam
        y: 236
        minimum: 1
        maximum: 100
        step: 1
        propertyName: "Seed"
        onPropertyValueChanged: {
            seedChanged(propertyValue)
        }
    }
}
