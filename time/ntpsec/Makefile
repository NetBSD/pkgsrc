# $NetBSD: Makefile,v 1.18 2022/07/30 01:22:07 tnn Exp $

DISTNAME=	ntpsec-1.2.1
CATEGORIES=	time
MASTER_SITES=	https://ftp.ntpsec.org/pub/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ntpsec.org/
COMMENT=	Hardened & improved NTP implementation derived from NTP Classic
LICENSE=	cc-by-v4.0 AND 2-clause-bsd AND modified-bsd AND mit

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=	waf-[0-9]*:../../devel/waf

USE_TOOLS+=		bison m4 pkg-config
WAF_CONFIGURE_ARGS+=	--python=${PYTHONBIN}
WAF_CONFIGURE_ARGS+=	--pyshebang=${PYTHONBIN}
# pkgsrc python PLIST logic expects all python-3.x extensions to use -O1,
# but I can't figure out how to pass it through waf, so disable precompiled
# python files for now ...
WAF_CONFIGURE_ARGS+=	--nopyc --nopyo
WAF_CONFIGURE_ARGS+=	--refclock=all
WAF_ENV+=		PYTHON_CONFIG=${PYTHONCONFIG}
WAF_ENV+=		BIN_A2X=${PREFIX}/bin/a2x
WAF_ENV+=		BIN_XSLTPROC=${PREFIX}/bin/xsltproc

RCD_SCRIPTS=		ntpd
PY_PATCHPLIST=		yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/waf/waf.mk"
.include "../../geography/gpsd/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_DEPMETHOD.libxslt?=	build
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
