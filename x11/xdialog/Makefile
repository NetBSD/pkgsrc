# $NetBSD: Makefile,v 1.27 2011/11/01 06:11:59 sbd Exp $
#

DISTNAME=		Xdialog-2.3.1
PKGNAME=		${DISTNAME:S/^X/x/}
PKGREVISION=		6
CATEGORIES=		x11 misc
MASTER_SITES=		http://xdialog.free.fr/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xdialog.dyns.net/
COMMENT=		X11 drop-in replacement for the curses dialog program

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		msgfmt
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

DOCDIR=			${PREFIX}/share/doc/html/xdialog
EGDIR=			${PREFIX}/share/examples/xdialog

CHECK_PORTABILITY_SKIP+=	samples/*

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR}

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.png ${DESTDIR}${DOCDIR}
	for f in Xmessage Xmore buildlist calendar chain checklist	\
		dselect editbox fselect gauge infobox infobox2 inputbox	\
		logbox logbox2 login menubox msgbox radiolist rangebox	\
		tailbox textbox timebox treeview yesno;			\
	do								\
		${INSTALL_SCRIPT} ${WRKSRC}/samples/$${f} ${DESTDIR}${EGDIR};	\
	done

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
