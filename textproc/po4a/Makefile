# $NetBSD: Makefile,v 1.22 2014/12/03 07:08:36 ryoon Exp $

DISTNAME=		po4a-0.45
CATEGORIES=		textproc
MASTER_SITES=		https://alioth.debian.org/frs/download.php/file/3942/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://po4a.alioth.debian.org/
COMMENT=		Tool for using gettext where it was not intended to be used

DEPENDS+=		p5-gettext>=1.01:../../devel/p5-gettext
DEPENDS+=		p5-SGMLS-[0-9]*:../../textproc/p5-SGMLS
DEPENDS+=		p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=		p5-Text-WrapI18N-[0-9]*:../../textproc/p5-Text-WrapI18N

USE_TOOLS+=		pkg-config perl:run msgmerge:run msgfmt:run

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/po4a/.packlist
REPLACE_PERL=		scripts/msguntypot po4a po4a-gettextize po4a-normalize
REPLACE_PERL+=		po4a-translate po4a-updatepo
REPLACE_PERL+=		lib/Locale/Po4a/*

MAKE_ENV+=		COLUMNS=76

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
