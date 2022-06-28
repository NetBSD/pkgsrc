# $NetBSD: Makefile,v 1.21 2022/06/28 11:36:48 wiz Exp $

.include "../../textproc/mecab/Makefile.common"

DISTNAME=		mecab-perl-${MECAB_VERSION}
PKGNAME=		p5-mecab-${MECAB_VERSION}
PKGREVISION=		11
CATEGORIES+=		perl5

COMMENT=		MeCab perl module
LICENSE=		gnu-gpl-v2 OR gnu-lgpl-v2.1 OR modified-bsd

PERL5_CONFIGURE=	yes
USE_LANGUAGES=		c++

PERL5_PACKLIST=		auto/MeCab/.packlist
REPLACE_PERL+=		test.pl

BUILDLINK_API_DEPENDS.mecab+=	mecab>=${MECAB_VERSION}

.include "../../textproc/mecab/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
