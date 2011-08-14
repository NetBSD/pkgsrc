# $NetBSD: Makefile,v 1.7 2011/08/14 16:06:02 obache Exp $

DISTNAME=      	Kwiki-Users-Remote-0.04
PKGREVISION=	4
PKGNAME=       	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki plugin to automatically set user name from HTTP authentication

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Kwiki>=0.37nb1:../../www/p5-Kwiki
DEPENDS+=	p5-Kwiki-UserName>=0.14:../../www/p5-Kwiki-UserName

PERL5_PACKLIST=		auto/Kwiki/Users/Remote/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
