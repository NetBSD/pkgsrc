# $NetBSD: Makefile,v 1.10 2013/05/31 12:42:28 wiz Exp $

DISTNAME=	Time-Clock-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Clock/
COMMENT=	Twenty-four hour clock object with nanosecond precision
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=		auto/Time/Clock/.packlist

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
