# $NetBSD: Makefile,v 1.32 2004/04/09 13:05:03 grant Exp $
#

DISTNAME=		mod_perl-1.29
PKGNAME=		ap-perl-1.29
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/} \
			http://perl.apache.org/dist/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://perl.apache.org/
COMMENT=		Module that embeds a Perl interpreter into Apache

CONFLICTS=		ap2-perl-[0-9]*

DEPENDS+=		${BUILDLINK_DEPENDS.apache}:../../www/apache
DEPENDS+=		{libperl>=${LIBPERL5_REQD},perl>=5.8.0}:../../lang/libperl
DEPENDS+=		p5-BSD-Resource>=1.10:../../devel/p5-BSD-Resource

USE_BUILDLINK3=		YES
APACHE_MODULE=		YES
LIBPERL5_REQD=		${_PERL5_REQD}
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/mod_perl/.packlist

MAKE_PARAMS+=		USE_APXS=1
MAKE_PARAMS+=		WITH_APXS=${APXS}
MAKE_PARAMS+=		EVERYTHING=1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/httpd/htdocs/manual/mod
	${INSTALL_DATA} ${WRKSRC}/htdocs/manual/mod/mod_perl.html \
		${PREFIX}/share/httpd/htdocs/manual/mod

.include "../../lang/perl5/module.mk"
.include "../../www/apache/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

.if exists(${PERL5_ARCHLIB}/DynaLoader_pic.o)
DYNALOADER_OBJ_PIC=	${PERL5_ARCHLIB}/DynaLoader_pic.o
.elif ${OPSYS} == "NetBSD"
DYNALOADER_OBJ_PIC=	${PERL5_ARCHLIB}/auto/DynaLoader/DynaLoader.a
.endif
MAKE_ENV+=	DYNALOADER_OBJ_PIC="${DYNALOADER_OBJ_PIC}"
