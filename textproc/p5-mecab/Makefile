# $NetBSD: Makefile,v 1.1.1.1 2007/05/12 13:55:03 obache Exp $
#

.include "../../textproc/mecab/Makefile.common"

DISTNAME=		mecab-perl-${MECAB_VERSION}
PKGNAME=		p5-mecab-${MECAB_VERSION}
CATEGORIES+=		perl5

COMMENT=		MeCab perl module

PERL5_CONFIGURE=	yes
USE_LANGUAGES=		c++

PERL5_PACKLIST=		auto/MeCab/.packlist
REPLACE_PERL+=		test.pl

.include "../../textproc/mecab/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
