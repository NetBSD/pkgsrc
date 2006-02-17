# $NetBSD: Makefile,v 1.1.1.1 2006/02/17 01:49:36 minskim Exp $

DISTNAME=	Jemplate-0.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/I/IN/INGY/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://search.cpan.org/~ingy/Jemplate/
COMMENT=	Javascript Templating with Template Toolkit

DEPENDS+=	p5-Template-Toolkit>=2.14:../../www/p5-Template-Toolkit

PERL5_PACKLIST=		auto/Jemplate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
