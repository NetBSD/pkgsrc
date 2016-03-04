# $NetBSD: Makefile,v 1.49 2016/03/04 01:28:02 leot Exp $

DISTNAME=	netsurf-all-3.4
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

# Avoid possible problems with shells that defines HOST
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
