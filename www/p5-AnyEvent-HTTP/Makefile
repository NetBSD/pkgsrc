# $NetBSD: Makefile,v 1.3 2010/07/19 04:51:16 seb Exp $

DISTNAME=	AnyEvent-HTTP-1.45
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=AnyEvent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/AnyEvent-HTTP/
COMMENT=	Perl 5 module providing simple but non-blocking HTTP/HTTPS client
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/AnyEvent/HTTP/.packlist

DEPENDS+=	p5-AnyEvent>=5:../../devel/p5-AnyEvent

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
