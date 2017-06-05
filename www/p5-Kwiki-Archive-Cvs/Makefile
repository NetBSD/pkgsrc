# $NetBSD: Makefile,v 1.14 2017/06/05 14:25:24 ryoon Exp $

DISTNAME=	Kwiki-Archive-Cvs-0.104
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
#HOMEPAGE=	http://search.cpan.org/dist/Kwiki-Archive-Cvs/
COMMENT=	Kwiki page archive using CVS

DEPENDS+=	p5-Kwiki>=0.39:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/Archive/Cvs/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
