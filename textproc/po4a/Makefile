# $NetBSD: Makefile,v 1.28 2016/07/09 06:39:07 wiz Exp $

DISTNAME=		po4a-0.47
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		https://alioth.debian.org/frs/download.php/file/4142/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://po4a.alioth.debian.org/
COMMENT=		Tool for using gettext where it was not intended to be used

DEPENDS+=		p5-gettext>=1.01:../../devel/p5-gettext
DEPENDS+=		p5-SGMLS-[0-9]*:../../textproc/p5-SGMLS
DEPENDS+=		p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=		p5-Text-WrapI18N-[0-9]*:../../textproc/p5-Text-WrapI18N
DEPENDS+=		p5-CPAN-Meta>=2.141170:../../devel/p5-CPAN-Meta
DEPENDS+=		p5-PerlIO-utf8_strict-[0-9]*:../../devel/p5-PerlIO-utf8_strict

USE_TOOLS+=		pkg-config perl:run msgmerge:run msgfmt:run

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/po4a/.packlist

REPLACE_PERL=		scripts/msguntypot po4a po4a-gettextize po4a-normalize
REPLACE_PERL+=		po4a-translate po4a-updatepo
REPLACE_PERL+=		lib/Locale/Po4a/*

DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_ENV+=		COLUMNS=76

# work around not to set PATH to msgmerge, please somebody to fix correctly
SUBST_CLASSES+=		path
SUBST_FILES.path=	po4a
SUBST_MESSAGE.path=	Fix msgmerge command path (not found)
SUBST_STAGE.path=	pre-configure
SUBST_SED.path=		-e 's|\"msgmerge\"|\"${PREFIX}/bin/msgmerge\"|;'

.include "../../lang/perl5/module.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
