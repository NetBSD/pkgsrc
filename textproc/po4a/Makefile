# $NetBSD: Makefile,v 1.20 2013/06/18 19:24:20 wiz Exp $

DISTNAME=		po4a-0.23
PKGREVISION=		11
CATEGORIES=		textproc
MASTER_SITES=		http://alioth.debian.org/download.php/1317/

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
REPLACE_PERL=		msguntypot po4a po4a-gettextize po4a-normalize
REPLACE_PERL+=		po4a-translate po4a-updatepo
REPLACE_PERL+=		lib/Locale/Po4a/Chooser.pm
REPLACE_PERL+=		lib/Locale/Po4a/Common.pm
REPLACE_PERL+=		lib/Locale/Po4a/Dia.pm
REPLACE_PERL+=		lib/Locale/Po4a/Docbook.pm
REPLACE_PERL+=		lib/Locale/Po4a/Guide.pm
REPLACE_PERL+=		lib/Locale/Po4a/KernelHelp.pm
REPLACE_PERL+=		lib/Locale/Po4a/LaTeX.pm
REPLACE_PERL+=		lib/Locale/Po4a/Man.pm
REPLACE_PERL+=		lib/Locale/Po4a/Po.pm
REPLACE_PERL+=		lib/Locale/Po4a/Pod.pm
REPLACE_PERL+=		lib/Locale/Po4a/Sgml.pm
REPLACE_PERL+=		lib/Locale/Po4a/TeX.pm
REPLACE_PERL+=		lib/Locale/Po4a/Text.pm
REPLACE_PERL+=		lib/Locale/Po4a/TransTractor.pm
REPLACE_PERL+=		lib/Locale/Po4a/Xml.pm

MAKE_ENV+=		COLUMNS=76

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
