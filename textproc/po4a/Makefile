# $NetBSD: Makefile,v 1.10 2008/06/04 22:10:11 tonnerre Exp $
#

DISTNAME=		po4a-0.23
PKGREVISION=		4
CATEGORIES=		textproc
MASTER_SITES=		http://alioth.debian.org/download.php/1317/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://alioth.debian.org/projects/po4a/
COMMENT=		Tool for using gettext where it was not intended to be used

DEPENDS+=		p5-gettext>=1.01:../../devel/p5-gettext
DEPENDS+=		p5-SGMLS-[0-9]*:../../textproc/p5-SGMLS
DEPENDS+=		p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=		p5-Text-WrapI18N-[0-9]*:../../textproc/p5-Text-WrapI18N

USE_TOOLS+=		pkg-config perl:run msgmerge:run msgfmt:run

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/po4a/.packlist
REPLACE_PERL=		msguntypot po4a po4a-gettextize po4a-normalize \
			po4a-translate po4a-updatepo

MAKE_ENV+=		COLUMNS=76

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
