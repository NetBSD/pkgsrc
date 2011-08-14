# $NetBSD: Makefile,v 1.3 2011/08/14 16:05:52 obache Exp $

DISTNAME=	FCGI-Client-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/FCGI-Client/
COMMENT=	Perl 5 client library for fastcgi protocol
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/FCGI/Client/.packlist

DEPENDS+=	p5-Any-Moose>=0.1:../../devel/p5-Any-Moose
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-autodie-[0-9]*:../../devel/p5-autodie

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
