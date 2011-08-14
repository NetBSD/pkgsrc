# $NetBSD: Makefile,v 1.6 2011/08/14 16:06:07 obache Exp $

DISTNAME=	Rose-URI-1.00
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Rose-URI/
COMMENT=	URI class for easy and efficient manipulation of URI components
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Rose-Object>=0.15:../../devel/p5-Rose-Object
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Rose/URI/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
