# $NetBSD: Makefile,v 1.16 2003/12/04 19:48:26 xtraeme Exp $
#

DISTNAME=		scrollkeeper-0.3.12
PKGREVISION=		3
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scrollkeeper/}	\
			${MASTER_SITE_GNOME:=sources/scrollkeeper/0.3/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://scrollkeeper.sourceforge.net/
COMMENT=		Open Document Cataloging Project

BUILD_USES_MSGFMT=	yes
DEPENDS=		docbook-xml>=4.2:../../textproc/docbook-xml

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS= 	--localstatedir=${SCROLLKEEPER_DATADIR}
CONFIGURE_ARGS+=	--sharedstatedir=${SCROLLKEEPER_DATADIR}
CONFIGURE_ARGS+= 	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"

.if ${LOCALBASE} == ${X11PREFIX}
CONFIGURE_ARGS+=	--with-omfdirs=${PREFIX}/share/omf
.else
CONFIGURE_ARGS+=	--with-omfdirs=${LOCALBASE}/share/omf:${X11PREFIX}/share/omf
.endif

INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

SCROLLKEEPER_DATADIR=	${PREFIX}/libdata/scrollkeeper
SCROLLKEEPER_REBUILDDB=	${PREFIX}/bin/scrollkeeper-rebuilddb
FILES_SUBST+=		SCROLLKEEPER_DATADIR="${SCROLLKEEPER_DATADIR}"
FILES_SUBST+=		SCROLLKEEPER_REBUILDDB="${SCROLLKEEPER_REBUILDDB}"

EGDIR=		${PREFIX}/share/examples/scrollkeeper
CONF_FILES=	${EGDIR}/scrollkeeper.conf ${PKG_SYSCONFDIR}/scrollkeeper.conf

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../textproc/intltool/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
