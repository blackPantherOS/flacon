/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * Flacon - audio File Encoder
 * https://github.com/flacon/flacon
 *
 * Copyright: 2012-2013
 *   Alexander Sokoloff <sokoloff.a@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * END_COMMON_COPYRIGHT_HEADER */


#ifndef OPUS_H
#define OPUS_H

#include "outformat.h"
#include "configdialog.h"
#include "ui_opus_config.h"

class OutFormat_Opus: public OutFormat
{
public:
    OutFormat_Opus();

    virtual QString encoderProgramName() const { return "opusenc"; }
    virtual QString gainProgramName() const { return ""; }

    virtual QStringList encoderArgs(Track *track, const QString &outFile) const;
    virtual QStringList gainArgs(const QStringList &files) const;

    QHash<QString, QVariant> defaultParameters() const;
    EncoderConfigPage *configPage(QWidget *parent = 0) const;
};


class ConfigPage_Opus: public EncoderConfigPage, private Ui::ConfigPage_Opus
{
    Q_OBJECT
public:
    explicit ConfigPage_Opus(QWidget *parent = 0);

    virtual void load();
    virtual void write();
};

#endif // OPUS_H
