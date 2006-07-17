# $NetBSD: Makefile,v 1.3 2006/07/17 17:51:03 wiz Exp $

DISTNAME=	Jemplate-0.18
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
