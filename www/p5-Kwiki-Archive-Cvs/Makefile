# $NetBSD: Makefile,v 1.3 2008/08/07 09:56:10 he Exp $

DISTNAME=	Kwiki-Archive-Cvs-0.103
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
#HOMEPAGE=	http://search.cpan.org/dist/Kwiki-Archive-Cvs/
COMMENT=	Kwiki page archive using CVS

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Kwiki>=0.39:../../www/p5-Kwiki

PERL5_PACKLIST=		auto/Kwiki/Archive/Cvs/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
