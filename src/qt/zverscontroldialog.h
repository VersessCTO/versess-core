// Copyright (c) 2017-2018 The PIVX developers
// Copyright (c) 2019 The Versess developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZVERSCONTROLDIALOG_H
#define ZVERSCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zvers/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZVersControlDialog;
}

class CZVersControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZVersControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZVersControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZVersControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZVersControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZVersControlDialog(QWidget *parent);
    ~ZVersControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZVersControlDialog *ui;
    WalletModel* model;
    PrivacyDialog* privacyDialog;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZVersControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZVERSCONTROLDIALOG_H
