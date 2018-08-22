# $NetBSD: Makefile,v 1.16 2018/08/22 09:47:36 wiz Exp $

DISTNAME=	FCGI-Client-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/FCGI-Client/
COMMENT=	Perl 5 client library for fastcgi protocol
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Any-Moose>=0.1:../../devel/p5-Any-Moose
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/FCGI/Client/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
