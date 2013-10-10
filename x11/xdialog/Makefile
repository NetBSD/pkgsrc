# $NetBSD: Makefile,v 1.42 2013/10/10 14:42:39 ryoon Exp $
#

DISTNAME=		Xdialog-2.3.1
PKGNAME=		${DISTNAME:S/^X/x/}
PKGREVISION=		19
CATEGORIES=		x11 misc
MASTER_SITES=		http://xdialog.free.fr/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xdialog.free.fr/
COMMENT=		X11 drop-in replacement for the curses dialog program
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		msgfmt
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

DOCDIR=			${PREFIX}/share/doc/xdialog
EGDIR=			${PREFIX}/share/examples/xdialog

CHECK_PORTABILITY_SKIP+=	samples/*

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR}

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.png ${DESTDIR}${DOCDIR}
.for f in Xmessage Xmore buildlist calendar chain checklist	\
		dselect editbox fselect gauge infobox infobox2 inputbox	\
		logbox logbox2 login menubox msgbox radiolist rangebox	\
		tailbox textbox timebox treeview yesno
	${INSTALL_SCRIPT} ${WRKSRC}/samples/${f} ${DESTDIR}${EGDIR}
.endfor

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
