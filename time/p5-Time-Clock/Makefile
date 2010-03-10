# $NetBSD: Makefile,v 1.4 2010/03/10 09:48:06 sno Exp $

DISTNAME=	Time-Clock-1.00
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Clock/
COMMENT=	Twenty-four hour clock object with nanosecond precision
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=		auto/Time/Clock/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
