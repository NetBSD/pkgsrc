# $NetBSD: Makefile,v 1.2 2017/09/02 14:28:52 taca Exp $
#

DISTNAME=	1.8.1
PKGNAME=	${PHP_PKG_PREFIX}-excel-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/PHPOffice/PHPExcel/archive/
DIST_SUBDIR=	${PKGBASE:S/${PHP_PKG_PREFIX}/php/1}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/PHPOffice/PHPExcel
COMMENT=	Pure PHP library for reading and writing spreadsheet files
LICENSE=	gnu-lgpl-v2 AND gnu-lgpl-v2.1

NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/PHPExcel-${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/CachedObjectStorage
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/CalcEngine
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/Calculation/Token
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/Cell
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/Chart/Renderer
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/Reader/Excel2007
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/Reader/Excel5
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/RichText
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/Shared/Escher/DgContainer/SpgrContainer
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/Shared/Escher/DggContainer/BstoreContainer/BSE
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/Shared/JAMA/utils
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/Shared/OLE/PPS
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/Shared/PCLZip
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/Shared/trend
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/Style
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/Worksheet/AutoFilter/Column
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/Worksheet/Drawing
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/Writer/Excel2007
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/Writer/Excel5
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/Writer/OpenDocument/Cell
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/Writer/PDF
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/locale/bg
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/locale/cs
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/locale/da
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/locale/de
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/locale/en/uk
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/locale/es
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/locale/fi
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/locale/fr
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/locale/hu
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/locale/it
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/locale/nl
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/locale/no
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/locale/pl
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/locale/pt/br
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/locale/ru
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/locale/sv
INSTALLATION_DIRS+=	share/${PKGBASE}/Classes/PHPExcel/locale/tr
#INSTALLATION_DIRS+=	share/doc/${PKGBASE}/assets/ClassDiagrams/Classes
#INSTALLATION_DIRS+=	share/doc/${PKGBASE}/assets/ClassDiagrams/Exports
#INSTALLATION_DIRS+=	share/doc/${PKGBASE}/markdown/CalculationEngine/FunctionReference
#INSTALLATION_DIRS+=	share/doc/${PKGBASE}/markdown/Features/Autofilters/images
#INSTALLATION_DIRS+=	share/doc/${PKGBASE}/markdown/Functions
#INSTALLATION_DIRS+=	share/doc/${PKGBASE}/markdown/Overview/images
#INSTALLATION_DIRS+=	share/doc/${PKGBASE}/markdown/ReadingSpreadsheetFiles
INSTALLATION_DIRS+=	share/examples/${PKGBASE}/images
INSTALLATION_DIRS+=	share/examples/${PKGBASE}/templates

.include "options.mk"

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} Classes/PHPExcel.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes; \
	${INSTALL_DATA} Classes/PHPExcel/*.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel; \
	${INSTALL_DATA} Classes/PHPExcel/CachedObjectStorage/* \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/CachedObjectStorage; \
	${INSTALL_DATA} Classes/PHPExcel/CalcEngine/* \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/CalcEngine; \
	${INSTALL_DATA} Classes/PHPExcel/Calculation/*.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Calculation; \
	${INSTALL_DATA} Classes/PHPExcel/Calculation/functionlist.txt \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Calculation; \
	${INSTALL_DATA} Classes/PHPExcel/Calculation/Token/Stack.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Calculation/Token; \
	${INSTALL_DATA} Classes/PHPExcel/Cell/* \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Cell; \
	${INSTALL_DATA} Classes/PHPExcel/Chart/*.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Chart; \
	${INSTALL_DATA} Classes/PHPExcel/Chart/Renderer/* \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Chart/Renderer; \
	${INSTALL_DATA} Classes/PHPExcel/Reader/*.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Reader; \
	${INSTALL_DATA} Classes/PHPExcel/Reader/Excel2007/* \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Reader/Excel2007; \
	${INSTALL_DATA} Classes/PHPExcel/Reader/Excel5/* \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Reader/Excel5; \
	${INSTALL_DATA} Classes/PHPExcel/RichText/* \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/RichText; \
	${INSTALL_DATA} Classes/PHPExcel/Shared/*.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Shared; \
	${INSTALL_DATA} Classes/PHPExcel/Shared/Escher/*.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Shared/Escher; \
	${INSTALL_DATA} Classes/PHPExcel/Shared/Escher/DgContainer/SpgrContainer.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Shared/Escher/DgContainer/SpgrContainer/SpContainer.php; \
	${INSTALL_DATA} Classes/PHPExcel/Shared/Escher/DggContainer/BstoreContainer.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Shared/Escher/DggContainer; \
	${INSTALL_DATA} Classes/PHPExcel/Shared/Escher/DggContainer/BstoreContainer/BSE.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Shared/Escher/DggContainer/BstoreContainer; \
	${INSTALL_DATA} Classes/PHPExcel/Shared/Escher/DggContainer/BstoreContainer/BSE/Blip.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Shared/Escher/DggContainer/BSE; \
	${INSTALL_DATA} Classes/PHPExcel/Shared/JAMA/*.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Shared/JAMA; \
	${INSTALL_DATA} Classes/PHPExcel/Shared/JAMA/utils/*.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Shared/JAMA/utils; \
	${INSTALL_DATA} Classes/PHPExcel/Shared/OLE/*.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Shared/OLE; \
	${INSTALL_DATA} Classes/PHPExcel/Shared/OLE/PPS/*.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Shared/OLE/PPS; \
	${INSTALL_DATA} Classes/PHPExcel/Shared/PCLZip/pclzip.lib.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Shared/PCLZip; \
	${INSTALL_DATA} Classes/PHPExcel/Shared/trend/* \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Shared/trend; \
	${INSTALL_DATA} Classes/PHPExcel/Style/* \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Style; \
	${INSTALL_DATA} Classes/PHPExcel/Worksheet/*.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Worksheet; \
	${INSTALL_DATA} Classes/PHPExcel/Worksheet/AutoFilter/Column.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Worksheet/AutoFilter; \
	${INSTALL_DATA} Classes/PHPExcel/Worksheet/AutoFilter/Column/Rule.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Worksheet/AutoFilter/Column; \
	${INSTALL_DATA} Classes/PHPExcel/Writer/*.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Writer; \
	${INSTALL_DATA} Classes/PHPExcel/Writer/Excel2007/* \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Writer/Excel2007; \
	${INSTALL_DATA} Classes/PHPExcel/Writer/Excel5/* \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Writer/Excel5; \
	${INSTALL_DATA} Classes/PHPExcel/Writer/PDF/* \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/Classes/PHPExcel/Writer/PDF; \
	for i in Classes/PHPExcel/locale/*; do \
	if [ "$$i" != "Classes/PHPExcel/locale/en" -a "$$i" != "Classes/PHPExcel/locale/pt" ]; then \
			${INSTALL_DATA} $$i/* \
				${DESTDIR}${PREFIX}/share/${PKGBASE}/$$i; \
		elif [ "$$i" = "Classes/PHPExcel/locale/en" ]; then \
			${INSTALL_DATA} $$i/uk/config \
				${DESTDIR}${PREFIX}/share/${PKGBASE}/$$i/uk; \
		elif [ "$$i" = "Classes/PHPExcel/locale/pt" ]; then \
			${INSTALL_DATA} $$i/config \
				${DESTDIR}${PREFIX}/share/${PKGBASE}/$$i; \
			${INSTALL_DATA} $$i/functions \
				${DESTDIR}${PREFIX}/share/${PKGBASE}/$$i; \
			${INSTALL_DATA} $$i/br/config \
				${DESTDIR}${PREFIX}/share/${PKGBASE}/$$i/br; \
			${INSTALL_DATA} $$i/br/functions \
				${DESTDIR}${PREFIX}/share/${PKGBASE}/$$i/br; \
		fi; \
	done; \
	${INSTALL_DATA} Examples/*.php \
		${DESTDIR}${PREFIX}/share/examples/${PKGBASE}; \
	${INSTALL_DATA} Examples/*.x* \
		${DESTDIR}${PREFIX}/share/examples/${PKGBASE}; \
	${INSTALL_DATA} Examples/GnumericTest.gnumeric \
		${DESTDIR}${PREFIX}/share/examples/${PKGBASE}; \
	${INSTALL_DATA} Examples/OOCalcTest.ods \
		${DESTDIR}${PREFIX}/share/examples/${PKGBASE}; \
	${INSTALL_DATA} Examples/SylkTest.slk \
		${DESTDIR}${PREFIX}/share/examples/${PKGBASE}; \
	${INSTALL_DATA} Examples/images/* \
		${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/images; \
	${INSTALL_DATA} Examples/templates/* \
		${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/templates

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
