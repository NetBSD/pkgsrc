# $NetBSD: Makefile,v 1.22 2001/11/22 09:11:08 martti Exp $
# FreeBSD Id: Makefile,v 1.12 1997/09/14 04:00:11 jfitz Exp
#

DISTNAME=	libwww-perl-5.61
PKGNAME=	p5-${DISTNAME:S/-perl-/-/}
SVR4_PKGNAME=	p5lww
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://www.linpro.no/lwp/
COMMENT=	perl5 library for WWW access

DEPENDS+= 	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Net-[0-9]*:../../net/p5-Net
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/libwww-perl/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL -n

.include "../../mk/bsd.pkg.mk"
