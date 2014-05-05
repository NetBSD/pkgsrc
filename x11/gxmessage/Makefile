# $NetBSD: Makefile,v 1.8 2014/05/05 00:48:30 ryoon Exp $
#

DISTNAME=	gxmessage-2.20.0
PKGREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	http://homepages.ihug.co.nz/~trmusson/stuff/
MASTER_SITES+=	${MASTER_SITE_GNU:=gxmessage/}

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://homepages.ihug.co.nz/~trmusson/programs.html
COMMENT=	GTK2+ based xmessage clone
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt pkg-config
TEXINFO_REQD=		4.0
INFO_FILES=		yes

EGDIR=			${PREFIX}/share/examples/gxmessage
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${EGDIR}

GX_FILES=	gtkrc gxaddress gxdialup gxdict gxman gxview nautilus-word-count

post-install:
	for a in ${GX_FILES}; do  \
		${INSTALL_DATA} ${WRKSRC}/examples/$$a ${DESTDIR}${EGDIR}/$$a;\
	done

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
