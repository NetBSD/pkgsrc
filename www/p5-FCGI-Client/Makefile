# $NetBSD: Makefile,v 1.13 2017/06/05 14:25:16 ryoon Exp $

DISTNAME=	FCGI-Client-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/FCGI-Client/
COMMENT=	Perl 5 client library for fastcgi protocol
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/FCGI/Client/.packlist

DEPENDS+=	p5-Any-Moose>=0.1:../../devel/p5-Any-Moose
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
#DEPENDS+=	{perl>=5.10.1,p5-autodie-[0-9]*}:../../devel/p5-autodie

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
