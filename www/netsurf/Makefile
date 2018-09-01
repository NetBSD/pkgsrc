# $NetBSD: Makefile,v 1.70 2018/09/01 18:01:35 leot Exp $

DISTNAME=	netsurf-all-3.8
PKGNAME=	${DISTNAME:S/-all//}
CATEGORIES=	www
MASTER_SITES=	http://download.netsurf-browser.org/netsurf/releases/source-full/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.netsurf-browser.org/
COMMENT=	Web browser for RISC OS and UNIX-like platforms
LICENSE=	gnu-gpl-v2 AND mit

BUILD_DEPENDS+=	lemon>=1.0:../../devel/lemon
BUILD_DEPENDS+=	re2c>=0.12:../../devel/re2c
BUILD_DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser

BUILD_TARGET=	build
USE_TOOLS+=	bison flex gmake perl:build pax pkg-config

SUBST_CLASSES+=			ssl-certs
SUBST_STAGE.ssl-certs=		pre-configure
SUBST_MESSAGE.ssl-certs=	Fixing hardcoded paths for SSL certs
SUBST_FILES.ssl-certs=		netsurf/frontends/beos/gui.cpp
SUBST_FILES.ssl-certs+=		netsurf/frontends/gtk/gui.c
SUBST_FILES.ssl-certs+=		netsurf/test/data/Choices-all
SUBST_FILES.ssl-certs+=		netsurf/test/data/Choices-full
SUBST_FILES.ssl-certs+=		netsurf/test/data/Choices-short
SUBST_SED.ssl-certs=		-e 's,/etc/ssl/certs,${SSLCERTS},'

# Avoid possible problems with already often defined HOST
MAKE_ENV+=	BUILD="${MACHINE_GNU_ARCH}--${LOWER_OPSYS}"
MAKE_ENV+=	HOST="${MACHINE_GNU_ARCH}--${LOWER_OPSYS}"

INSTALLATION_DIRS+=	share/netsurf bin

BUILDLINK_TRANSFORM+=	rm:-Werror
CFLAGS.NetBSD+=		-D_NETBSD_SOURCE	# needed for strcasestr(3) and strndup(3)

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
