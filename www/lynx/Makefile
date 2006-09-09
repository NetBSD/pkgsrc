# $NetBSD: Makefile,v 1.91 2006/09/09 02:46:09 obache Exp $

#
# NOTE: Please do not enable the lynxcgi feature unless it is lynx
# version 2.8.6dev.15 or later.  There is a known security issue
# with this feature in earlier versions.
#

DISTNAME=	lynx2.8.5
PKGNAME=	lynx-2.8.5.5
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://lynx.isc.org/${DISTNAME}/ \
		ftp://ftp.nl.uu.net/pub/unix/www/lynx/${DISTNAME}/ \
		ftp://ftp.cyf-kr.edu.pl/pub/unix/lynx/${DISTNAME}/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/WWW/lynx/${DISTNAME}/
EXTRACT_SUFX=	.tar.bz2

PATCH_DIST_STRIP= -p1
PATCH_SITES=	${MASTER_SITES:=patches/}
PATCHFILES=	2.8.5rel.2.patch.gz 2.8.5rel.3.patch.gz
PATCHFILES+=	2.8.5rel.4.patch.gz 2.8.5rel.5.patch.gz

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://lynx.isc.org/
COMMENT=	Alphanumeric display oriented World-Wide Web Client

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DIST_SUBDIR=		lynx
WRKSRC=			${WRKDIR}/${DISTNAME:S/./-/g}
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INSTALL_TARGET=		install-full install-lss
MAKE_FILE=       	makefile

CONFIGURE_ENV+=		GZIP=${TOOLS_GZIP_CMD:Q}
USE_TOOLS+=		gzip msgfmt

.include "options.mk"

# For nls/gettext
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--with-nls-datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--without-included-gettext

# With SSL, lynx can get https:// and snews:// URL's.
CONFIGURE_ARGS+=	--with-ssl

# Note: --enable-{default-colors,scrollbar} are simply ignored
# for certain settings of --with-screen.
CONFIGURE_ARGS+=	--with-screen=${SCREENTYPE:Q}
CONFIGURE_ARGS+=	--enable-default-colors
CONFIGURE_ARGS+=	--enable-scrollbar

# Install gzip'ed help files to ${PREFIX}/share/lynx
CONFIGURE_ARGS+=	--libdir="${PREFIX}/share/lynx"
CONFIGURE_ARGS+=	--enable-gzip-help --with-zlib

# Miscellaneous
CONFIGURE_ARGS+=	--enable-externs
CONFIGURE_ARGS+=	--enable-source-cache

# Experimental features
CONFIGURE_ARGS+=	--enable-file-upload
CONFIGURE_ARGS+=	--enable-justify-elts
CONFIGURE_ARGS+=	--enable-kbd-layout
CONFIGURE_ARGS+=	--enable-nested-tables
CONFIGURE_ARGS+=	--enable-prettysrc
CONFIGURE_ARGS+=	--enable-read-eta

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/lynx
	${FIND} ${PREFIX}/share/lynx -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	# gets created when applying 2.8.5.2 patch -- remove on
	# patchless update
	${RM} -f ${PREFIX}/share/lynx/lynx_doc/CHANGES.orig_dist

.include "../../mk/bsd.pkg.mk"
