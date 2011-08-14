# $NetBSD: Makefile,v 1.3 2011/08/14 16:05:52 obache Exp $

DISTNAME=	Dancer-1.175
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SU/SUKRIA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perldancer.org/
COMMENT=	Perl 5 lightweight yet powerful web application framework
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Dancer/.packlist

DEPENDS+=	p5-HTTP-Body-[0-9]*:../../www/p5-HTTP-Body
DEPENDS+=	p5-HTTP-Server-Simple-PSGI>=0.11:../../www/p5-HTTP-Server-Simple-PSGI
DEPENDS+=	p5-MIME-Types-[0-9]*:../../mail/p5-MIME-Types
DEPENDS+=	p5-Test-Simple>=0.87:../../devel/p5-Test-Simple
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
