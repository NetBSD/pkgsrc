# $NetBSD: Makefile,v 1.26 2004/10/03 00:18:21 tv Exp $
#

DISTNAME=		scrollkeeper-0.3.14
PKGREVISION=		5
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scrollkeeper/}	\
			${MASTER_SITE_GNOME:=sources/scrollkeeper/0.3/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://scrollkeeper.sourceforge.net/
COMMENT=		Open Document Cataloging Project

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_USES_MSGFMT=	yes
DEPENDS=		docbook-xml>=4.2:../../textproc/docbook-xml

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS= 	--localstatedir=${SCROLLKEEPER_DATADIR}
CONFIGURE_ARGS+=	--sharedstatedir=${SCROLLKEEPER_DATADIR}
CONFIGURE_ARGS+= 	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+= 	--with-partial-db-dir=db
CONFIGURE_ARGS+= 	--with-xml-catalog=${BUILDLINK_PREFIX.xmlcatmgr}/share/xml/catalog

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

XML_ENTRIES=	public "-//Scrollkeeper//DTD Contents List V1.0//EN" \
		${PREFIX}/share/xml/scrollkeeper/dtds/scrollkeeper-cl.dtd
XML_ENTRIES+=	public "-//OMF//DTD Scrollkeeper OMF Variant V1.0//EN" \
		${PREFIX}/share/xml/scrollkeeper/dtds/scrollkeeper-omf.dtd
XML_ENTRIES+=	public "-//Open Source Metadata Framework (OMF) //DTD OMF.dtd V1.1//EN" \
		${PREFIX}/share/xml/scrollkeeper/dtds/scrollkeeper-omf.dtd

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"

.include "../../mk/bsd.pkg.mk"
