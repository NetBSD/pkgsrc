# $NetBSD: Makefile,v 1.12 1998/04/28 09:46:05 tron Exp $
# FreeBSD Id: Makefile,v 1.14 1997/10/30 05:15:19 jkh Exp
#

DISTNAME=	qt-1.33
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.cdrom.com/pub/linux/sunsite/Incoming/ \
		ftp://ftp.kde.org/pub/qt/TGZ/ \
		ftp://ftp.troll.no/qt/source/

MAINTAINER=	tron@netbsd.org

USE_X11=	yes

QTDIR=	${PREFIX}

MAN1=		moc.1
MAN3=		qaccel.3 qapplication.3 qarray.3 qbitarray.3 \
		qbitmap.3 qbitval.3 qboxlayout.3 qbrush.3 qbuffer.3 \
		qbutton.3 qbuttongroup.3 qbytearray.3 \
		qcheckbox.3 qclipboard.3 qcloseevent.3 \
		qcollection.3 qcolor.3 qcolorgroup.3 \
		qcombobox.3 qconnection.3 qcursor.3 \
		qcustomevent.3 qdatastream.3 qdate.3 \
		qdatetime.3 qdialog.3 qdict.3 qdictiterator.3 \
		qdir.3 qdoublevalidator.3 qevent.3 qfile.3 \
		qfiledialog.3 qfileinfo.3 qfocusevent.3 qfont.3 \
		qfontinfo.3 qfontmetrics.3 qframe.3 qgarray.3 \
		qgcache.3 qgcacheiterator.3 qgdict.3 qgdictiterator.3 \
		qglist.3 qglistiterator.3 qgmanager.3 qgridlayout.3 \
		qgroupbox.3 qhboxlayout.3 qimage.3 \
		qimageio.3 qintdict.3 qintdictiterator.3 \
		qintvalidator.3 \
		qiodevice.3 qkeyevent.3 qlabel.3 qlayout.3 \
		qlcdnumber.3 \
		qlineedit.3 qlist.3 qlistbox.3 qlistboxitem.3 \
		qlistboxpixmap.3 qlistboxtext.3 qlistiterator.3 \
		qlnode.3 qmenubar.3 qmenudata.3 qmessagebox.3 \
		qmouseevent.3 qmoveevent.3 qmultilineedit.3 qobject.3 \
		qmovie.3 \
		qpaintdevice.3 qpaintdevicemetrics.3 qpainter.3 \
		qpaintevent.3 qpalette.3 qpen.3 qpicture.3 \
		qpixmap.3 qpixmapcache.3 qpoint.3 \
		qpointarray.3 qpointval.3 qpopupmenu.3 qprinter.3 \
		qprogressbar.3 qprogressdialog.3 qptrdict.3 \
		qptrdictiterator.3 \
		qpushbutton.3 qqueue.3 qradiobutton.3 \
		qrangecontrol.3 qrect.3 qregexp.3 qregion.3 \
		qresizeevent.3 qscrollbar.3 qsenderobject.3 \
		qsemimodal.3 \
		qshared.3 qsignal.3 qsize.3 qslider.3 \
		qsocketnotifier.3 qstack.3 qstrilist.3 qstring.3 \
		qstrlist.3 qtabbar.3 qtabdialog.3 qtableview.3 \
		qtextstream.3 qtime.3 \
		qtimer.3 qtimerevent.3 qtooltip.3 qtooltipgroup.3 \
		qtsmanip.3 qvalidator.3 qvboxlayout.3 qwidget.3 \
		qwindow.3 qwmatrix.3 QAccel.3 QApplication.3 \
		QArray.3 QBitArray.3 QBitmap.3 QBitVal.3 \
		QBoxLayout.3 QBrush.3 \
		QBuffer.3 QButton.3 QButtonGroup.3 \
		QByteArray.3 QCheckBox.3 QClipboard.3 \
		QCloseEvent.3 QCollection.3 QColor.3 \
		QColorGroup.3 QComboBox.3 QConnection.3 \
		QCursor.3 QCustomEvent.3 QDataStream.3 QDate.3 \
		QDateTime.3 QDialog.3 QDict.3 QDictIterator.3 \
		QDir.3 QDoubleValidator.3 QEvent.3 QFile.3 \
		QFileDialog.3 QFileInfo.3 QFocusEvent.3 QFont.3 \
		QFontInfo.3 QFontMetrics.3 QFrame.3 QGArray.3 \
		QGCache.3 QGCacheIterator.3 QGDict.3 QGDictIterator.3 \
		QGList.3 QGListIterator.3 QGManager.3 \
		QGridLayout.3 QGroupBox.3 QHBoxLayout.3 QImage.3 \
		QImageIO.3 QIntDict.3 QIntDictIterator.3 \
		QIntValidator.3 \
		QIODevice.3 QKeyEvent.3 QLCDNumber.3 QLabel.3 \
		QLayout.3 \
		QLineEdit.3 QList.3 QListBox.3 QListBoxItem.3 \
		QListBoxPixmap.3 QListBoxText.3 QListIterator.3 \
		QLNode.3 QMenuBar.3 QMenuData.3 QMessageBox.3 \
		QMovie.3 \
		QMouseEvent.3 QMoveEvent.3 QMultiLineEdit.3 QObject.3 \
		QPaintDevice.3 QPaintDeviceMetrics.3 QPainter.3 \
		QPaintEvent.3 QPalette.3 QPen.3 QPicture.3 \
		QPixmap.3 QPixmapCache.3 QPoint.3 QPointVal.3\
		QPointArray.3 QPopupMenu.3 QPrinter.3 \
		QProgressBar.3 QProgressDialog.3 \
		QPtrDict.3 QPtrDictIterator.3 \
		QPushButton.3 QQueue.3 QRadioButton.3 \
		QRangeControl.3 QRect.3 QRegExp.3 QRegion.3 \
		QResizeEvent.3 QScrollBar.3 QSenderObject.3 \
		QSemiModal.3 QVBoxLayout.3 QValidator.3 \
		QShared.3 QSignal.3 QSize.3 QSlider.3 \
		QSocketNotifier.3 QStack.3 QStrIList.3 QString.3 \
		QStrList.3 QTabBar.3 QTabDialog.3 QTableView.3 \
		QTextStream.3 QTime.3 \
		QTimer.3 QTimerEvent.3 QToolTip.3 QToolTipGroup.3 \
		QTSManip.3 QWidget.3 QWindow.3 QWMatrix.3

do-configure:
	cd ${WRKSRC} && make netbsd-gcc-shared

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc ${QTDIR}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/libqt.so.1.33 ${QTDIR}/lib
	${LDCONFIG} || ${TRUE}
	${MKDIR} ${QTDIR}/include/qt
	${INSTALL_DATA} ${WRKSRC}/include/* ${QTDIR}/include/qt
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${QTDIR}/man/man1
	@(for PAGE in ${MAN3}; do \
	    set - X `head -1 ${WRKSRC}/man/man3/$${PAGE}qt`; \
	    if [ $$# -eq 3 ] && [ "$$2" = .so ]; then \
		${ECHO} ${LN} -s `basename $$3 | ${SED} s/qt$$//` \
		${QTDIR}/man/man3/$${PAGE}; \
		${LN} -s `basename $$3 | ${SED} s/qt$$//` \
		${QTDIR}/man/man3/$${PAGE}; \
	    else \
		${ECHO} ${INSTALL_MAN} ${WRKSRC}/man/man3/$${PAGE}qt \
		${QTDIR}/man/man3/$${PAGE}; \
		${INSTALL_MAN} ${WRKSRC}/man/man3/$${PAGE}qt \
		${QTDIR}/man/man3/$${PAGE}; \
	    fi; \
	 done)
	${MKDIR} ${QTDIR}/share/doc/qt
	${INSTALL_DATA} ${WRKSRC}/README ${QTDIR}/share/doc/qt
	${INSTALL_DATA} ${WRKSRC}/README.QT ${QTDIR}/share/doc/qt

.include "../../mk/bsd.pkg.mk"
