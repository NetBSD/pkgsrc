# $NetBSD: Makefile,v 1.9 2012/01/26 19:18:26 rhaen Exp $

DISTNAME=	Rose-DateTime-0.537
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/dist/Rose-DateTime/
COMMENT=	DateTime helper functions and objects for Rose
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+= 	p5-Rose-Object>=0.82:../../devel/p5-Rose-Object
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime

PERL5_PACKLIST=		auto/Rose/DateTime/.packlist

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
