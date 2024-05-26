# $NetBSD: Makefile,v 1.67 2024/05/26 07:06:43 adam Exp $

DISTNAME=	po4a-0.72
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mquinson/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://po4a.org/
COMMENT=	Tool for using gettext where it was not intended to be used
LICENSE=	gnu-gpl-v2

DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
DEPENDS+=	p5-gettext>=1.01:../../devel/p5-gettext
DEPENDS+=	p5-SGMLS-[0-9]*:../../textproc/p5-SGMLS
DEPENDS+=	p5-Syntax-Keyword-Try-[0-9]*:../../devel/p5-Syntax-Keyword-Try
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Pod-Parser-[0-9]*:../../textproc/p5-Pod-Parser
DEPENDS+=	p5-Text-WrapI18N-[0-9]*:../../textproc/p5-Text-WrapI18N
DEPENDS+=	p5-PerlIO-utf8_strict-[0-9]*:../../devel/p5-PerlIO-utf8_strict
DEPENDS+=	p5-Unicode-LineBreak-[0-9]*:../../textproc/p5-Unicode-LineBreak
DEPENDS+=	p5-YAML-Tiny-[0-9]*:../../textproc/p5-YAML-Tiny
TEST_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

.include "../../mk/bsd.prefs.mk"

# sync with pkgtools/pkgdiff/Makefile
.if	${OPSYS} == "SunOS" ||	\
	${OPSYS} == "OSF1" ||	\
	${OPSYS} == "Darwin" && empty(OSX_VERSION:M[0-9].*) && empty(OSX_VERSION:M1[0-2].*)
DEPENDS+=		diffutils-[0-9]*:../../devel/diffutils
DIFF?=			${PREFIX}/bin/gdiff
TOOLS_PATH.diff=	${DIFF}
.else
DIFF?=			diff
.endif

.include "options.mk"

USE_TOOLS+=		pkg-config perl:run diff:run
USE_TOOLS+=		msgconv:run msgfmt:run msgmerge:run

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/po4a/.packlist

REPLACE_PERL=		msguntypot po4a po4a-gettextize po4a-normalize
REPLACE_PERL+=		po4a-translate po4a-updatepo
REPLACE_PERL+=		lib/Locale/Po4a/*

MAKE_ENV+=		COLUMNS=76

.if ${OPSYS} == "SunOS"
# If /dev/null is a symlink into /devices/pseudo/, msgfmt won't follow it
# (maybe because it's in a different filesystem?)
# So we expand the symlink (if any) before building.
PO4A_DEVNULL_cmd=	readlink -f /dev/null | sed -e 's|@|\\@|'
PO4A_DEVNULL=		${PO4A_DEVNULL_cmd:sh}
.else
PO4A_DEVNULL=		/dev/null
.endif

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	lib/Locale/Po4a/Po.pm Po4aBuilder.pm
SUBST_FILES.paths+=	msguntypot po4a po4a-updatepo
SUBST_STAGE.paths=	pre-configure
SUBST_VARS.paths=	PREFIX DIFF SH PO4A_DEVNULL

.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
