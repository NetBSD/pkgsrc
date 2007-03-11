# $NetBSD: Makefile,v 1.1.1.1 2007/03/11 15:57:30 obache Exp $

DISTNAME=	Kwiki-Archive-Cvs-0.102
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki page archive using CVS

DEPENDS+=	p5-Kwiki>=0.38:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/Archive/Cvs/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
