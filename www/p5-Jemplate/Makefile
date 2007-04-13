# $NetBSD: Makefile,v 1.6 2007/04/13 04:06:39 hiramatsu Exp $

DISTNAME=	Jemplate-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/I/IN/INGY/

MAINTAINER=	hiramatsu@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~ingy/Jemplate/
COMMENT=	Javascript Templating with Template Toolkit

DEPENDS+=	p5-Template-Toolkit>=2.14:../../www/p5-Template-Toolkit
DEPENDS+=	p5-File-Find-Rule>=0.30:../../devel/p5-File-Find-Rule

PERL5_PACKLIST=		auto/Jemplate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
