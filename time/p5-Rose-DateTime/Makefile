# $NetBSD: Makefile,v 1.21 2019/08/11 13:24:10 wiz Exp $

DISTNAME=	Rose-DateTime-0.540
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Rose-DateTime
COMMENT=	DateTime helper functions and objects for Rose
LICENSE=	${PERL5_LICENSE}

DEPENDS+= 	p5-Rose-Object>=0.82:../../devel/p5-Rose-Object
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime

PERL5_PACKLIST=		auto/Rose/DateTime/.packlist

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
